package ru.uchimznaem.uchimznaemhelper;

import android.util.Log;

import org.xmlpull.v1.XmlPullParser;
import org.xmlpull.v1.XmlPullParserFactory;

import java.io.InputStream;
import java.io.StringReader;
import java.util.ArrayList;
import java.util.List;

import ru.uchimznaem.uchimznaemhelper.entities.Building;
import ru.uchimznaem.uchimznaemhelper.entities.Floor;
import ru.uchimznaem.uchimznaemhelper.entities.Room;

/**
 * Created by Vladimir Ulyanov
 */

public class MapUtils {

    public static Building loadBuilding(){
        Building ret = new Building();
        List<Floor> list = new ArrayList<Floor>();
        //todo replace with loadFloorFromRes
        //list.add(loadFloorFromRes(R.drawable.scheme));
        list.add(loadDummyFloor(1));
        list.add(loadDummyFloor(2));
        list.add(loadDummyFloor(3));

        return ret;
    }
    public static void testLoad() {
        // todo ipetrushin
        // переписать с поддержкой загрузки XML
        String str = "<vector xmlns:android=\"http://schemas.android.com/apk/res/android\"\n" +
                "    android:width=\"29700dp\"\n" +
                "    android:height=\"21000dp\"\n" +
                "    android:viewportWidth=\"29700\"\n" +
                "    android:viewportHeight=\"21000\">\n" +
                "\n" +
                "    <path\n" +
                "        android:name=\"classroom1\"\n" +
                "        android:fillColor=\"#000000\"\n" +
                "        android:pathData=\"M 19176 12593 L 21112 12593 L 21112 9718 L 23247 9718 L 23247 12593 L 28423 12593 L 28423 13947 L 20196 13947 L 20196 13773 L 18290 13766 L 5844 8810 L 6922 6107 L 7799 6457 L 6950 8588 L 9010 9408 L 9860 7279 L 10901 7694 L 10052 9823 L 18201 13067 L 19176 13075 Z\" />\n" +
                "    <path\n" +
                "        android:name=\"classroom2\"\n" +
                "        android:fillColor=\"#2B2A29\"\n" +
                "        android:pathData=\"M 17036 13290 L 13270 11788 L 13282 11759 L 17048 13260 Z\" />\n" +
                "  </vector>";
        try {
            XmlPullParserFactory factory = XmlPullParserFactory.newInstance();
            XmlPullParser parser = factory.newPullParser();
            parser.setInput(new StringReader(str));
            int eventtype = parser.getEventType();
            while (eventtype != XmlPullParser.END_DOCUMENT) {
                if (eventtype == XmlPullParser.START_TAG && parser.getName().equals("path")) {
                    Log.d("my", "" + parser.getAttributeValue(0));
                }
                eventtype = parser.next();
            }
        } catch (Exception e) {}
    }

    /*
    Болванка - заготовка для генерации инфо об этаже
     */
    public static Floor loadDummyFloor(int floorNumber){
        Floor f = new Floor();
        f.setNumber(floorNumber);
        f.setMapId(R.drawable.scheme);
        List<Room> list = new ArrayList<>();
        list.add(new Room("1", "Операционная № 1"));
        list.add(new Room("2", "Палата №1"));
        list.add(new Room("3", "Палата №2"));
        list.add(new Room("4", "Палата №3"));
        list.add(new Room("5", "Палата №4"));

        f.setRooms(list);
        return f;
    }

    public static Floor loadFloorFromRes(int resId){
        //todo

        return new Floor();
    }

}
