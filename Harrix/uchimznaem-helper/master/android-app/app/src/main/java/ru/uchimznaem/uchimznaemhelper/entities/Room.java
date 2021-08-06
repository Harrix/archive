package ru.uchimznaem.uchimznaemhelper.entities;

/**
 * Created by Vladimir Ulyanov
 */

public class Room {

    String id;
    String title;

    public int getCenter_x() {
        return center_x;
    }

    public int getCenter_y() {
        return center_y;
    }

    int center_x, center_y;

    public Room(){

    }

    @Override
    public String toString() {
        //return "t: "+title + " ("+center_x+","+center_y+")";
        return getTitle();
    }

    public String getTitle() {
        return title;
    }

    public void setTitle(String title) {
        this.title = title;
    }

    public Room(String id, String title, int x, int y) {
        this.id = id;
        this.title = title;
        this.center_x = x;
        this.center_y = y;

    }

    public String getId() {
        return id;
    }

    public void setId(String id) {
        this.id = id;
    }
}
