package ru.uchimznaem.uchimznaemhelper.repository;

import java.util.List;

import ru.uchimznaem.uchimznaemhelper.entities.Book;

/**
 * @author Vladimir Ulyanov.
 */

public interface BooksRepository {
    List<Book> getBooks();
}
