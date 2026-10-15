package io.github.locme.banjotooie;

import android.content.pm.PackageInfo;
import android.content.pm.PackageManager;
import android.content.res.AssetManager;
import android.os.Bundle;
import android.util.Log;

import org.libsdl.app.SDLActivity;

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

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        unpackGameFiles();
        super.onCreate(savedInstanceState);
    }

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
