package ru.uchimznaem.uchimznaemhelper;

import android.annotation.SuppressLint;
import android.content.Context;
import android.net.Uri;
import android.os.Bundle;
import android.support.v4.app.Fragment;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.webkit.WebView;
import android.widget.AdapterView;
import android.widget.BaseAdapter;
import android.widget.ListAdapter;
import android.widget.ListView;
import android.widget.TextView;

import java.util.List;

import ru.uchimznaem.uchimznaemhelper.entities.Book;
import ru.uchimznaem.uchimznaemhelper.repository.BooksRepository;
import ru.uchimznaem.uchimznaemhelper.repository.ResBooksRepository;

/**
 * @author Vladimir Ulyanov.
 */

@SuppressLint("ValidFragment")
class OnkoBooksFragment extends Fragment {
    private static final String TAG = "Onkobooks";
    WebView wvBook;
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        View root = inflater.inflate(R.layout.fragment_books, container, false);
        ListView lvBooks = (ListView) root.findViewById(R.id.lvbooks);
        wvBook = root.findViewById(R.id.wvBook);
        BooksRepository booksRepo = new ResBooksRepository();
        BooksAdapter booksAdapter = new BooksAdapter(booksRepo);
        lvBooks.setAdapter(booksAdapter);
        lvBooks.setOnItemClickListener(booksAdapter);

        //test
        //String testUrl= Uri.parse("file:///android_res/raw/books/Chudik/Chudik.html").toString();
        /*String testUrl= "file:///android_asset/books/Chudik/Chudik.html";
        wvBook.loadUrl(testUrl);
*/
        return root;
    }

    private class BooksAdapter extends BaseAdapter implements ListAdapter, AdapterView.OnItemClickListener {
        List<Book> books;
        public BooksAdapter(BooksRepository repo) {
            books = repo.getBooks();
        }

        @Override
        public int getCount() {
            return books.size();
        }

        @Override
        public Object getItem(int i) {
            return books.get(i);
        }

        @Override
        public long getItemId(int i) {
            return i;
        }

        @Override
        public View getView(int position, View convertView, ViewGroup parent) {
            View view = convertView;
            if (convertView == null){
                getActivity().getSystemService(Context.LAYOUT_INFLATER_SERVICE);
                view = LayoutInflater.from(parent.getContext()).inflate(R.layout.list_layout_item_1, parent, false);
            }

            assert(view != null);
            TextView tv = (TextView) view;
            assert(tv != null);
            Book book = books.get(position);
            String title = book.getTitle();
            tv.setText(title);

            return view;
        }

        @Override
        public void onItemClick(AdapterView<?> adapterView, View view, int pos, long id) {
            Book book = books.get(pos);
            Uri uri = book.getUri();
            String url = book.getUri().toString();
            Log.d(TAG, url);
            wvBook.loadUrl(url);
        }
    }
}

