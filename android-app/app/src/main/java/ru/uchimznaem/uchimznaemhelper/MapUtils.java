package ru.uchimznaem.uchimznaemhelper;

import android.content.Context;
import android.util.Log;

import org.xmlpull.v1.XmlPullParser;
import org.xmlpull.v1.XmlPullParserFactory;

import java.io.InputStream;
import java.io.StringReader;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

import ru.uchimznaem.uchimznaemhelper.entities.Building;
import ru.uchimznaem.uchimznaemhelper.entities.Floor;
import ru.uchimznaem.uchimznaemhelper.entities.Room;

/**
 * Created by Vladimir Ulyanov
 */

public class MapUtils {
    public static Building building = null;

    public static void startLoadBuilding(Context ctx) {
        building = loadBuilding(ctx);
    }

    public static Building loadBuilding(Context ctx){
        Building ret = new Building();
        List<Floor> list = new ArrayList<Floor>();
        //todo replace with loadFloorFromRes
        //list.add(loadFloorFromRes(R.drawable.scheme));
        list.add(loadDummyFloor(1, ctx));
        //list.add(loadDummyFloor(2 ,ctx));
        //list.add(loadDummyFloor(3, ctx));
        ret.setFloors(list);
        return ret;
    }
    public static List<Room> testLoad(Context ctx ) {


        // todo ipetrushin
        // переписать с поддержкой загрузки XML
        String xml ;
        try {
            xml = "";
            InputStream is = ctx.getResources().getAssets().open("scheme.xml");
            Scanner sc = new Scanner(is);
            while (sc.hasNextLine()) {
                xml += sc.nextLine();
            }
            XmlPullParserFactory factory = XmlPullParserFactory.newInstance();
            XmlPullParser parser = factory.newPullParser();
            parser.setInput(new StringReader(xml));
            int eventtype = parser.getEventType();
            int room_id = 0;
            List<Room> list = new ArrayList<>();
            while (eventtype != XmlPullParser.END_DOCUMENT) {
                if (eventtype == XmlPullParser.START_TAG && parser.getName().equals("path")) {
                    Log.d("my", "Attributes " + parser.getAttributeCount() + " " + parser.getAttributeName(0));

                    if (parser.getAttributeCount() > 2 && (Character.isUpperCase(parser.getAttributeValue(0).charAt(0)))) {
                        Log.d("my",parser.getAttributeValue(2));
                        String[] pathData = parser.getAttributeValue(2).split(" ");
                        room_id ++;
                        int room_x = Integer.parseInt(pathData[1]);
                        int room_y = Integer.parseInt(pathData[2]);
                        Log.d("my", String.format("name: %s, x: %d, y: %d", parser.getAttributeValue(0), room_x, room_y));
                        Room r = new Room(Integer.toString(room_id), parser.getAttributeValue(0), room_x, room_y);
                        list.add(r);
                    }
                }
                eventtype = parser.next();
            }
            Log.d("my", "Loaded " + list.size() + " rooms");
            return list;
        } catch (Exception e) {}
        return new  ArrayList<Room>();

    }

    /*
    Болванка - заготовка для генерации инфо об этаже
     */
    public static Floor loadDummyFloor(int floorNumber, Context context){
        Floor f = new Floor();
        f.setNumber(floorNumber);
        f.setMapId(R.drawable.scheme);
        List<Room> list = testLoad(context);
                //new ArrayList<>();
        /*
        list.add(new Room("1", "Операционная № 1", 0,0));
        list.add(new Room("2", "Палата №1", 0,0));
        list.add(new Room("3", "Палата №2", 0,0));
        list.add(new Room("4", "Палата №3", 0,0));
        list.add(new Room("5", "Палата №4", 0,0));
*/
        f.setRooms(list);
        //Log.d("my", "Loaded rooms in MapUtils: "+list.size());
        return f;
    }

    public static Floor loadFloorFromRes(int resId){
        //todo

        return new Floor();
    }

}
