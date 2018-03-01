package ru.uchimznaem.uchimznaemhelper.repository;

import java.util.ArrayList;
import java.util.List;
import java.util.NoSuchElementException;

import ru.uchimznaem.uchimznaemhelper.R;
import ru.uchimznaem.uchimznaemhelper.entities.Building;
import ru.uchimznaem.uchimznaemhelper.entities.Floor;
import ru.uchimznaem.uchimznaemhelper.entities.Room;

/**
 * Created by Vladimir Ulyanov
 */

public class StubMapRepository implements MapRepository {


    /**
     * Болванка - заготовка для гегнерации инфо об этаже
     *
     * @param floorNumber номер этажа
     * @return Объект этажа с одинаковым содержимым
     */
    private Floor createDummyFloor(int floorNumber) {
        Floor f = new Floor();
        f.setNumber(floorNumber);
        f.setMapId(R.drawable.scheme);
        List<Room> list = new ArrayList<>();
        list.add(new Room("1", "Игровая комната № 1"));
        list.add(new Room("2", "Палата №1"));
        list.add(new Room("3", "Палата №2"));
        list.add(new Room("4", "Палата №3"));
        list.add(new Room("5", "Палата №4"));

        f.setRooms(list);
        return f;
    }


    @Override
    public Building getBuilding() {
        Building ret = new Building();
        List<Floor> list = new ArrayList<Floor>();
        list.add(createDummyFloor(1));
        list.add(createDummyFloor(2));
        list.add(createDummyFloor(3));
        list.add(createDummyFloor(4));
        ret.setFloors(list);

        return ret;
    }

    @Override
    public Floor getFloor(int floorNumber) {
        for (Floor floor : getBuilding().getFloors()) {
            if (floor.getNumber().equals(floorNumber)) return floor;
        }
        throw new NoSuchElementException("Unknown floor number");
    }
}
