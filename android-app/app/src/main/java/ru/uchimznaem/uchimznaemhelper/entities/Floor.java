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

    public void setNumber(Integer number) {
        this.number = number;
    }

    public void setRooms(List<Room> rooms) {
        this.rooms = rooms;
    }

    public void setMapId(int mapId) {
        this.mapId = mapId;
    }
}
