package ru.uchimznaem.uchimznaemhelper.repository;

import android.content.Context;
import android.util.Log;

import org.xmlpull.v1.XmlPullParser;
import org.xmlpull.v1.XmlPullParserFactory;

import java.io.InputStream;
import java.io.StringReader;
import java.util.ArrayList;
import java.util.List;
import java.util.NoSuchElementException;
import java.util.Scanner;

import ru.uchimznaem.uchimznaemhelper.R;
import ru.uchimznaem.uchimznaemhelper.entities.Building;
import ru.uchimznaem.uchimznaemhelper.entities.Floor;
import ru.uchimznaem.uchimznaemhelper.entities.Room;

/**
 *
 * @author Ivan Petrushin
 *
 * Реализация репозитория по получению информациюю о картах этажей здания
 * на основе ресурсов (информация подгружается из XML векторного представления
 */
public class ResourcesMapRepository implements MapRepository {
    Context ctx;
    static Building b = null;

    public ResourcesMapRepository(Context ctx) {
        this.ctx = ctx;
        getBuilding();
    }

    @Override
    public Building getBuilding() {
        if (b==null) {
            b = loadBuilding(ctx);
        }
        return b;
    }

    @Override
    public Floor getFloor(int floorNumber) {
        for (Floor floor : getBuilding().getFloors()) {
            if (floor.getNumber().equals(floorNumber)) return floor;
        }
        throw new NoSuchElementException("Unknown floor number");
    }

    private Building loadBuilding(Context ctx){
        Building ret = new Building();
        List<Floor> list = new ArrayList<Floor>();
        //list.add(loadFloorFromRes(R.drawable.scheme));
        list.add(loadFloorFromXML(1, "scheme.xml", R.drawable.scheme));
        //list.add(loadFloorFromXML(2 ,ctx));
        //list.add(loadFloorFromXML(3, ctx));
        ret.setFloors(list);
        return ret;
    }

    private List<Room> loadRooms(String xmlPath) {

        // переписать с поддержкой загрузки XML
        String xml ;
        try {
            xml = "";
            //InputStream is = ctx.getResources().getAssets().open("scheme.xml");
            InputStream is = ctx.getResources().getAssets().open(xmlPath);
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
    private Floor loadFloorFromXML(int floorNumber, String xmlPath, int mapId){
        Floor f = new Floor();
        f.setNumber(floorNumber);
        f.setMapId(mapId);
        List<Room> list = loadRooms(xmlPath);
        f.setRooms(list);
        return f;
    }
}
