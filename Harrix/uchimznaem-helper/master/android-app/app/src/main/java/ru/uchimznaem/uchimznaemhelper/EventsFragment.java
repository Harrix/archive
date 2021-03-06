package ru.uchimznaem.uchimznaemhelper;

import android.database.Cursor;
import android.os.Bundle;
import android.support.v4.app.Fragment;
import android.support.v4.widget.SimpleCursorAdapter;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ListView;

/**
 * @author ipetrushin, Vladimir Ulyanov
 */


public class EventsFragment extends Fragment {

    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        int[] fields = new int[]{R.id.item_id, R.id.item_name, R.id.item_room};
        String[] headers = new String[]{"_id", "nameroom", "begin"};

        View root = inflater.inflate(R.layout.fragment_events, container, false);
        ListView lvEvents = (ListView) root.findViewById(R.id.lvevents);
        MainActivity activity = (MainActivity) getActivity();
        Cursor c = activity.mDb.rawQuery("SELECT id AS _id, name||' в кабинете ' || room AS nameroom, datetime(start, 'unixepoch', 'localtime') AS begin FROM events;", null);
        SimpleCursorAdapter cursorAdapter = new SimpleCursorAdapter(activity, R.layout.events_item, c, headers, fields, SimpleCursorAdapter.FLAG_AUTO_REQUERY);
        lvEvents.setAdapter(cursorAdapter);
        return root;
    }
}
