package ru.uchimznaem.uchimznaemhelper.repository;

import android.net.Uri;

import java.util.ArrayList;
import java.util.List;

import ru.uchimznaem.uchimznaemhelper.R;
import ru.uchimznaem.uchimznaemhelper.entities.Book;

/**
 * @author Vladimir Ulyanov.
 */

public class ResBooksRepository implements BooksRepository {
    @Override
    public List<Book> getBooks() {
        List<Book> books = new ArrayList<>();

        Uri path = Uri.parse("file:///android_asset/books/Chudik/Chudik.html");
        Book chudikBook = new Book("Чудик", path);
        books.add(chudikBook);
        return books;
    }
}
