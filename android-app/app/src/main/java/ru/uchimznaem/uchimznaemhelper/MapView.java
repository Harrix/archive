package ru.uchimznaem.uchimznaemhelper;

import android.content.Context;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.graphics.drawable.Drawable;
import android.util.AttributeSet;
import android.util.Log;
import android.view.MotionEvent;
import android.view.View;

import ru.uchimznaem.uchimznaemhelper.entities.Room;


public class MapView extends View {
    float x = 0, y = 0, touch_x = 0, touch_y = 0, x_offset = 0, y_offset = 0;
    final int MAP_WIDTH = 1284 , MAP_HEIGHT = 534;
    float cWidth = 400, cHeight = 300;

    Drawable map;
    public MapView(Context context, AttributeSet attrs) {

        super(context, attrs);
        map = getContext().getDrawable(R.drawable.scheme);


    }

    public void centerTo(Room room) {
        
    }
    @Override
    protected void onDraw(Canvas canvas) {
        cWidth = canvas.getWidth(); cHeight = canvas.getHeight();

        float w = canvas.getWidth();
        float h = canvas.getHeight();
        int dx = (int) (touch_x - x);
        int dy = (int) (touch_y - y);
        map.setBounds((int) (-dx + x_offset), (int) (-dy + y_offset), (int) (-dx + x_offset) + MAP_WIDTH, (int) (-dy + y_offset ) + MAP_HEIGHT);

        map.draw(canvas);

    }

    @Override
    public boolean onTouchEvent(MotionEvent event) {

        // todo
        // сделать перемещение
        x = event.getX(); y = event.getY();

        if (event.getAction() == MotionEvent.ACTION_DOWN) {
            touch_x = x; touch_y = y;
        }
        else {
            if (event.getAction() == MotionEvent.ACTION_UP) {

                x_offset -= touch_x - x; touch_x = x;
                y_offset -= touch_y - y; touch_y = y;
                Log.d("my", String.format("x: %.1f, y: %.1f", x, y));
            }
        }

        invalidate();
        return true;
    }
}
