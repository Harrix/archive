package ru.uchimznaem.uchimznaemhelper.entities;

/**
 * Created by Vladimir Ulyanov
 */

public class Room {

    String id;
    String title;

    public Room(){

    }

    public String getTitle() {
        return title;
    }

    public void setTitle(String title) {
        this.title = title;
    }

    public Room(String id, String title) {
        this.id = id;
        this.title = title;
    }

    public String getId() {
        return id;
    }

    public void setId(String id) {
        this.id = id;
    }
}
