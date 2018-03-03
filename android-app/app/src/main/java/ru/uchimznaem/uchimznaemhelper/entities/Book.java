package ru.uchimznaem.uchimznaemhelper.entities;

import android.net.Uri;


/**
 * @author Vladimir Ulyanov.
 */

public class Book {
    String title;
    Uri uri;

    public Book(String title, Uri uri) {
        this.title = title;
        this.uri = uri;
    }

    public String getTitle() {
        return title;
    }

    public void setTitle(String title) {
        this.title = title;
    }

    public Uri getUri() {
        return uri;
    }

    public void setUri(Uri uri) {
        this.uri = uri;
    }
}
