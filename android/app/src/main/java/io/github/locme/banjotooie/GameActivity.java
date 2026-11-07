package io.github.locme.banjotooie;

import android.content.Context;
import android.content.pm.PackageInfo;
import android.content.pm.PackageManager;
import android.content.res.AssetManager;
import android.os.Bundle;
import android.util.Log;
import android.view.InputDevice;
import android.view.KeyEvent;
import android.view.MotionEvent;
import android.view.SurfaceHolder;
import android.widget.FrameLayout;

import org.libsdl.app.SDLActivity;
import org.libsdl.app.SDLSurface;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;

/**
 * Runs the game: SDL's activity loads libSDL2.so and libmain.so (the port) and calls its SDL_main.
 * Before that, the menu files packed in the APK (game_files/) are unpacked into the internal folder,
 * which the game uses as its working directory (src/android/android_platform.cpp).
 */
public class GameActivity extends SDLActivity {
    private static final String TAG = "BanjoTooie";
    private static final String ASSET_ROOT = "game_files";

    private TouchOverlay touchOverlay;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        unpackGameFiles();
        super.onCreate(savedInstanceState);
        if (getPackageManager().hasSystemFeature(PackageManager.FEATURE_TOUCHSCREEN)) {
            touchOverlay = new TouchOverlay(this);
            addContentView(touchOverlay, new FrameLayout.LayoutParams(
                FrameLayout.LayoutParams.MATCH_PARENT, FrameLayout.LayoutParams.MATCH_PARENT));
        }
    }

    // The touch controls fade out when not touched and while a controller is used. SDL still gets every event.
    @Override
    public boolean dispatchTouchEvent(MotionEvent event) {
        if (touchOverlay != null) {
            touchOverlay.noteTouch(event);
        }
        return super.dispatchTouchEvent(event);
    }

    @Override
    public boolean dispatchKeyEvent(KeyEvent event) {
        if (touchOverlay != null && fromController(event.getSource())) {
            touchOverlay.noteController();
        }
        return super.dispatchKeyEvent(event);
    }

    @Override
    public boolean dispatchGenericMotionEvent(MotionEvent event) {
        if (touchOverlay != null && fromController(event.getSource())) {
            touchOverlay.noteController();
        }
        return super.dispatchGenericMotionEvent(event);
    }

    private static boolean fromController(int source) {
        return (source & (InputDevice.SOURCE_GAMEPAD | InputDevice.SOURCE_JOYSTICK)) != 0;
    }

    @Override
    protected SDLSurface createSDLSurface(Context context) {
        return new GameSurface(context);
    }

    /**
     * SDL's surface view, which also tells the game when the window's surface goes and comes back (the app
     * going to the background and back). RT64 draws to that surface with Vulkan, so its swap chain has to be
     * released before SDL lets go of the surface, and made again on the new one (src/android/android_platform.cpp).
     */
    private static class GameSurface extends SDLSurface {
        GameSurface(Context context) {
            super(context);
        }

        @Override
        public void surfaceDestroyed(SurfaceHolder holder) {
            // Waits (up to 2 s) for RT64 to release its swap chain while the surface is still there.
            nativeSurfaceLost();
            super.surfaceDestroyed(holder);
        }

        @Override
        public void surfaceChanged(SurfaceHolder holder, int format, int width, int height) {
            super.surfaceChanged(holder, format, width, height);
            // surfaceCreated gave SDL the new surface; the next frame shown makes the swap chain on it.
            nativeSurfaceReady();
        }
    }

    private static native void nativeSurfaceLost();
    private static native void nativeSurfaceReady();

    @Override
    protected void onDestroy() {
        super.onDestroy();
        // The runtime keeps its state in globals, so the next start needs a fresh process.
        System.exit(0);
    }

    /** Unpacks game_files/ once per installed version of the app. */
    private void unpackGameFiles() {
        File target = getFilesDir();
        File marker = new File(target, "game_files_version.txt");
        String version;
        try {
            PackageInfo info = getPackageManager().getPackageInfo(getPackageName(), 0);
            version = info.versionName + " " + info.lastUpdateTime;
        } catch (PackageManager.NameNotFoundException e) {
            version = "unknown";
        }
        try {
            if (marker.exists() && new String(Files.readAllBytes(marker.toPath()), StandardCharsets.UTF_8).equals(version)) {
                return;
            }
            copyAssetTree(getAssets(), ASSET_ROOT, target);
            Files.write(marker.toPath(), version.getBytes(StandardCharsets.UTF_8));
        } catch (IOException e) {
            Log.e(TAG, "Could not unpack the game files", e);
        }
    }

    private static void copyAssetTree(AssetManager assets, String path, File target) throws IOException {
        String[] children = assets.list(path);
        if (children == null || children.length == 0) {
            // A file (the asset manager lists files as having no children).
            try (InputStream in = assets.open(path); OutputStream out = new FileOutputStream(target)) {
                byte[] buffer = new byte[1 << 16];
                int read;
                while ((read = in.read(buffer)) > 0) {
                    out.write(buffer, 0, read);
                }
            }
            return;
        }
        if (!target.isDirectory() && !target.mkdirs()) {
            throw new IOException("Could not create " + target);
        }
        for (String child : children) {
            copyAssetTree(assets, path + "/" + child, new File(target, child));
        }
    }
}
