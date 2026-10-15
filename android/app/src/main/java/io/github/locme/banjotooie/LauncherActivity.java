package io.github.locme.banjotooie;

import android.app.Activity;
import android.content.Intent;
import android.graphics.Color;
import android.net.Uri;
import android.os.Bundle;
import android.view.Gravity;
import android.widget.Button;
import android.widget.LinearLayout;
import android.widget.TextView;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;

/**
 * First screen. When no ROM is installed yet it asks the player to pick their own Banjo-Tooie ROM,
 * copies it to picked_rom.z64 in the app folder (the game checks and stores it when it starts),
 * then starts the game. With a ROM installed it starts the game straight away.
 */
public class LauncherActivity extends Activity {
    private static final int PICK_ROM = 1;
    // The name the runtime stores the checked ROM under (game_id + ".z64").
    private static final String STORED_ROM = "bt.n64.us.1.0.z64";
    static final String PICKED_ROM = "picked_rom.z64";
    // Larger than any N64 cartridge.
    private static final long MAX_ROM_SIZE = 64L * 1024 * 1024;

    private TextView message;
    private Button pickButton;

    /** Where saves, settings, mods and the ROM go: the same folder as SDL_AndroidGetExternalStoragePath(). */
    static File appFolder(Activity activity) {
        File folder = activity.getExternalFilesDir(null);
        return folder != null ? folder : activity.getFilesDir();
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        File folder = appFolder(this);
        if (new File(folder, STORED_ROM).exists() || new File(folder, PICKED_ROM).exists()) {
            startGame();
            return;
        }

        LinearLayout layout = new LinearLayout(this);
        layout.setOrientation(LinearLayout.VERTICAL);
        layout.setGravity(Gravity.CENTER);
        layout.setPadding(64, 64, 64, 64);
        layout.setBackgroundColor(Color.BLACK);

        message = new TextView(this);
        message.setTextColor(Color.WHITE);
        message.setTextSize(18);
        message.setGravity(Gravity.CENTER);
        message.setText("To play, pick your own Banjo-Tooie ROM (US release, .z64, .n64 or .v64).\n"
            + "It is copied into the app, so you only need to do this once.");
        layout.addView(message);

        pickButton = new Button(this);
        pickButton.setText("Choose ROM");
        pickButton.setOnClickListener(v -> pickRom());
        LinearLayout.LayoutParams params = new LinearLayout.LayoutParams(
            LinearLayout.LayoutParams.WRAP_CONTENT, LinearLayout.LayoutParams.WRAP_CONTENT);
        params.topMargin = 48;
        layout.addView(pickButton, params);

        setContentView(layout);
    }

    private void pickRom() {
        Intent intent = new Intent(Intent.ACTION_OPEN_DOCUMENT);
        intent.addCategory(Intent.CATEGORY_OPENABLE);
        intent.setType("*/*");
        startActivityForResult(intent, PICK_ROM);
    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, Intent data) {
        super.onActivityResult(requestCode, resultCode, data);
        if (requestCode != PICK_ROM || resultCode != RESULT_OK || data == null || data.getData() == null) {
            return;
        }
        Uri uri = data.getData();
        pickButton.setEnabled(false);
        message.setText("Copying the ROM...");
        new Thread(() -> {
            String error = copyRom(uri);
            runOnUiThread(() -> {
                if (error == null) {
                    startGame();
                } else {
                    message.setText(error);
                    pickButton.setEnabled(true);
                }
            });
        }).start();
    }

    /** Copies the picked file to picked_rom.z64. Returns null when done, else what went wrong. */
    private String copyRom(Uri uri) {
        File folder = appFolder(this);
        File temp = new File(folder, PICKED_ROM + ".part");
        try (InputStream in = getContentResolver().openInputStream(uri);
             OutputStream out = new FileOutputStream(temp)) {
            if (in == null) {
                return "That file could not be opened. Please pick another.";
            }
            byte[] buffer = new byte[1 << 16];
            long total = 0;
            int read;
            boolean first = true;
            while ((read = in.read(buffer)) > 0) {
                if (first) {
                    first = false;
                    if (read < 4 || !isN64Rom(buffer)) {
                        temp.delete();
                        return "That file is not an N64 ROM. Please pick your Banjo-Tooie ROM.";
                    }
                }
                total += read;
                if (total > MAX_ROM_SIZE) {
                    temp.delete();
                    return "That file is too big to be an N64 ROM. Please pick your Banjo-Tooie ROM.";
                }
                out.write(buffer, 0, read);
            }
        } catch (IOException | SecurityException e) {
            temp.delete();
            return "The ROM could not be copied (" + e.getMessage() + "). Please try again.";
        }
        File picked = new File(folder, PICKED_ROM);
        picked.delete();
        if (!temp.renameTo(picked)) {
            temp.delete();
            return "The ROM could not be saved. Please check the phone has free space.";
        }
        return null;
    }

    /** The first word of an N64 ROM in any of its three byte orders (.z64, .v64, .n64). */
    private static boolean isN64Rom(byte[] b) {
        int word = ((b[0] & 0xFF) << 24) | ((b[1] & 0xFF) << 16) | ((b[2] & 0xFF) << 8) | (b[3] & 0xFF);
        return word == 0x80371240 || word == 0x37804012 || word == 0x40123780;
    }

    private void startGame() {
        startActivity(new Intent(this, GameActivity.class));
        finish();
    }
}
