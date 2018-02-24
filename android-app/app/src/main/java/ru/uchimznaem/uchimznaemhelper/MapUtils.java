package ru.uchimznaem.uchimznaemhelper;

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

    /*
    Болванка - заготовка для гегнерации инфо об этаже
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
