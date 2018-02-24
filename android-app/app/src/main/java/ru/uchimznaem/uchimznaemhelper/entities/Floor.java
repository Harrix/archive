package ru.uchimznaem.uchimznaemhelper.entities;

import java.util.List;

/**
 * Created by Vladimir Ulyanov
 */

public class Floor {
    Integer number;
    List<Room> rooms;
    int mapId;

    public Integer getNumber() {
        return number;
    }

    public List<Room> getRooms() {
        return rooms;
    }

    public int getMapId() {
        return mapId;
    }
}
