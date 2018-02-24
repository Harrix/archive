package ru.uchimznaem.uchimznaemhelper;

import android.content.Context;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.graphics.drawable.Drawable;
import android.util.AttributeSet;
import android.view.MotionEvent;
import android.view.View;

import ru.uchimznaem.uchimznaemhelper.entities.Room;


public class MapView extends View {
    float x = 0, y = 0;
    final int MAP_WIDTH = 2720, MAP_HEIGHT = 1130;

    Drawable map;
    public MapView(Context context, AttributeSet attrs) {

        super(context, attrs);
        map = getContext().getDrawable(R.drawable.scheme);
    }

    public void centerTo(Room room) {
        
    }
    @Override
    protected void onDraw(Canvas canvas) {
        //Paint p = new Paint();
        //canvas.drawColor(Color.GRAY);

        float w = canvas.getWidth();
        float h = canvas.getHeight();
        int dx = (int) ((x - w/2)/w * MAP_WIDTH);
        int dy = (int) ((y - h/2)/h * MAP_HEIGHT);
        map.setBounds(dx, dy, dx + MAP_WIDTH, dy + MAP_HEIGHT);

        map.draw(canvas);

    }

    @Override
    public boolean onTouchEvent(MotionEvent event) {
        x = event.getX(); y = event.getY();
        invalidate();
        return true;
    }
}
