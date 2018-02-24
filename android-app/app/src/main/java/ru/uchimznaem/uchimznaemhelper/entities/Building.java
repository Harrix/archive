package ru.uchimznaem.uchimznaemhelper.entities;

import java.util.List;

/**
 * Created by Vladimir Ulyanov.
 */

public class Building {
    List<Floor> floors;
    String title;

    public Building(){

    }

    public Building(List<Floor> floors, String title) {
        this.floors = floors;
        this.title = title;
    }

    public List<Floor> getFloors() {
        return floors;
    }

    public void setFloors(List<Floor> floors) {
        this.floors = floors;
    }

    public String getTitle() {
        return title;
    }

    public void setTitle(String title) {
        this.title = title;
    }
}
