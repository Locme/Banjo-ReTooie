package io.github.locme.banjotooie;

import android.content.Context;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.view.MotionEvent;
import android.view.View;

/**
 * On-screen controls for a phone: two sticks (left: Banjo, right: the C buttons), A, B, L, R, Z and
 * Start. The state goes to the game's virtual controller (src/android/android_platform.cpp).
 * Touches that start away from the controls are not taken, so the game's menus still get them.
 * The controls fade out after a few seconds without a touch, and when a controller is used; the next touch
 * on the screen (GameActivity passes every one to noteTouch) brings them back.
 */
public class TouchOverlay extends View {
    static final int BTN_A = 1;
    static final int BTN_B = 1 << 1;
    static final int BTN_START = 1 << 2;
    static final int BTN_L = 1 << 3;
    static final int BTN_R = 1 << 4;
    static final int BTN_Z = 1 << 5;

    private static final int STICK_LEFT = 0;
    private static final int STICK_RIGHT = 1;
    private static final int NONE = -1;

    private static final long IDLE_MS = 6000;
    private static final long FADE_MS = 400;

    /** A round control: centre and radius as fractions of the view's shorter side (or width, for x). */
    private static final class Control {
        final float cx, cy;   // fractions of the view width and height
        final boolean stick;
        final int bit;        // button bit, or the stick index
        final String label;
        Control(float cx, float cy, boolean stick, int bit, String label) {
            this.cx = cx; this.cy = cy; this.stick = stick; this.bit = bit; this.label = label;
        }
    }

    private final Control[] controls = {
        new Control(0.13f, 0.62f, true, STICK_LEFT, ""),
        new Control(0.70f, 0.62f, true, STICK_RIGHT, ""),
        new Control(0.91f, 0.62f, false, BTN_A, "A"),
        new Control(0.78f, 0.86f, false, BTN_B, "B"),
        new Control(0.08f, 0.10f, false, BTN_L, "L"),
        new Control(0.92f, 0.10f, false, BTN_R, "R"),
        new Control(0.22f, 0.10f, false, BTN_Z, "Z"),
        new Control(0.50f, 0.10f, false, BTN_START, "Start"),
    };

    // Which control each finger (pointer id) is holding, and where it is now.
    private final int[] pointerControl = new int[10];
    private final float[] pointerX = new float[10];
    private final float[] pointerY = new float[10];

    private boolean shown = true;
    private final Runnable idleHide = new Runnable() {
        @Override
        public void run() {
            hide();
        }
    };

    private int buttons = 0;
    private int leftX = 0, leftY = 0, rightX = 0, rightY = 0;

    private final Paint fill = new Paint(Paint.ANTI_ALIAS_FLAG);
    private final Paint ring = new Paint(Paint.ANTI_ALIAS_FLAG);
    private final Paint text = new Paint(Paint.ANTI_ALIAS_FLAG);

    public TouchOverlay(Context context) {
        super(context);
        setFocusable(false);
        for (int i = 0; i < pointerControl.length; i++) {
            pointerControl[i] = NONE;
        }
        ring.setStyle(Paint.Style.STROKE);
        ring.setStrokeWidth(4f);
        ring.setColor(Color.argb(140, 255, 255, 255));
        fill.setColor(Color.argb(60, 255, 255, 255));
        text.setColor(Color.argb(200, 255, 255, 255));
        text.setTextAlign(Paint.Align.CENTER);
        restartIdleTimer();
    }

    /** Called for every touch on the screen, before the controls or the game see it. Shows the controls. */
    void noteTouch(MotionEvent event) {
        int action = event.getActionMasked();
        removeCallbacks(idleHide);
        if (!shown) {
            shown = true;
            animate().cancel();
            animate().alpha(1f).setDuration(100).start();
        } else if (getAlpha() < 1f) {
            animate().cancel();
            setAlpha(1f);
        }
        // The timer only runs while no finger is down.
        if (action == MotionEvent.ACTION_UP || action == MotionEvent.ACTION_CANCEL) {
            restartIdleTimer();
        }
    }

    /** Called when a controller is used: hides the controls until the screen is touched. */
    void noteController() {
        if (shown) {
            hide();
        }
    }

    private void restartIdleTimer() {
        removeCallbacks(idleHide);
        postDelayed(idleHide, IDLE_MS);
    }

    /** Fades the controls out and lets go of everything held, so no stick or button stays pressed. */
    private void hide() {
        removeCallbacks(idleHide);
        shown = false;
        animate().cancel();
        animate().alpha(0f).setDuration(FADE_MS).start();
        for (int i = 0; i < pointerControl.length; i++) {
            pointerControl[i] = NONE;
        }
        update();
    }

    private float unit() {
        return Math.min(getWidth(), getHeight());
    }

    private float radius(Control c) {
        return (c.stick ? 0.12f : 0.065f) * unit();
    }

    private float centreX(Control c) {
        return c.cx * getWidth();
    }

    private float centreY(Control c) {
        return c.cy * getHeight();
    }

    /** The control under (x, y), or null. */
    private Control hit(float x, float y) {
        for (Control c : controls) {
            float dx = x - centreX(c);
            float dy = y - centreY(c);
            float r = radius(c) * (c.stick ? 1.3f : 1.2f);
            if (dx * dx + dy * dy <= r * r) {
                return c;
            }
        }
        return null;
    }

    @Override
    public boolean onTouchEvent(MotionEvent event) {
        int action = event.getActionMasked();
        boolean handled = false;

        if (action == MotionEvent.ACTION_DOWN || action == MotionEvent.ACTION_POINTER_DOWN) {
            int index = event.getActionIndex();
            int id = event.getPointerId(index);
            Control c = hit(event.getX(index), event.getY(index));
            if (c != null && id < pointerControl.length) {
                pointerControl[id] = indexOf(c);
                handled = true;
            }
        } else if (action == MotionEvent.ACTION_UP || action == MotionEvent.ACTION_POINTER_UP
                || action == MotionEvent.ACTION_CANCEL) {
            int index = event.getActionIndex();
            int id = event.getPointerId(index);
            if (action == MotionEvent.ACTION_CANCEL) {
                for (int i = 0; i < pointerControl.length; i++) {
                    pointerControl[i] = NONE;
                }
            } else if (id < pointerControl.length) {
                handled = pointerControl[id] != NONE;
                pointerControl[id] = NONE;
            }
        } else if (action == MotionEvent.ACTION_MOVE) {
            for (int i = 0; i < event.getPointerCount(); i++) {
                int id = event.getPointerId(i);
                if (id < pointerControl.length && pointerControl[id] != NONE) {
                    handled = true;
                }
            }
        }

        // Track each held finger's position, so a stick follows it.
        for (int i = 0; i < event.getPointerCount(); i++) {
            int id = event.getPointerId(i);
            if (id < pointerControl.length) {
                pointerX[id] = event.getX(i);
                pointerY[id] = event.getY(i);
            }
        }
        update();
        return handled;
    }

    private int indexOf(Control c) {
        for (int i = 0; i < controls.length; i++) {
            if (controls[i] == c) {
                return i;
            }
        }
        return NONE;
    }

    /** Works out the button and stick state from the fingers held down, and sends it on. */
    private void update() {
        int newButtons = 0;
        int lx = 0, ly = 0, rx = 0, ry = 0;
        for (int id = 0; id < pointerControl.length; id++) {
            int ci = pointerControl[id];
            if (ci == NONE) {
                continue;
            }
            Control c = controls[ci];
            if (c.stick) {
                float r = radius(c);
                float dx = (pointerX[id] - centreX(c)) / r;
                float dy = (pointerY[id] - centreY(c)) / r;
                float len = (float) Math.sqrt(dx * dx + dy * dy);
                if (len > 1f) {
                    dx /= len;
                    dy /= len;
                }
                int x = Math.round(dx * 32767f);
                int y = Math.round(dy * 32767f);
                if (c.bit == STICK_LEFT) {
                    lx = x;
                    ly = y;
                } else {
                    rx = x;
                    ry = y;
                }
            } else {
                newButtons |= c.bit;
            }
        }
        if (newButtons != buttons || lx != leftX || ly != leftY || rx != rightX || ry != rightY) {
            buttons = newButtons;
            leftX = lx;
            leftY = ly;
            rightX = rx;
            rightY = ry;
            send();
            invalidate();
        }
    }

    private void send() {
        try {
            nativeSetState(buttons, leftX, leftY, rightX, rightY);
        } catch (UnsatisfiedLinkError e) {
            // The game's library is not loaded yet; the next change is sent.
        }
    }

    /** Implemented in android_platform.cpp. */
    private static native void nativeSetState(int buttons, int leftX, int leftY, int rightX, int rightY);

    @Override
    protected void onDraw(Canvas canvas) {
        super.onDraw(canvas);
        for (Control c : controls) {
            float x = centreX(c), y = centreY(c), r = radius(c);
            boolean held = isHeld(c);
            if (c.stick) {
                canvas.drawCircle(x, y, r, ring);
                float knobX = x, knobY = y;
                if (c.bit == STICK_LEFT) {
                    knobX += leftX / 32767f * r;
                    knobY += leftY / 32767f * r;
                } else {
                    knobX += rightX / 32767f * r;
                    knobY += rightY / 32767f * r;
                }
                canvas.drawCircle(knobX, knobY, r * 0.4f, held ? fill : ring);
            } else {
                canvas.drawCircle(x, y, r, held ? fill : ring);
                text.setTextSize(r * 0.7f);
                canvas.drawText(c.label, x, y + r * 0.25f, text);
            }
        }
    }

    private boolean isHeld(Control c) {
        if (c.stick) {
            return false;
        }
        return (buttons & c.bit) != 0;
    }
}
