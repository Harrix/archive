package ru.uchimznaem.uchimznaemhelper;

import android.database.Cursor;
import android.os.Bundle;
import android.support.v4.app.ListFragment;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.ListAdapter;

import java.util.ArrayList;
import java.util.List;

/**
 * @author Vladimir Ulyanov
 */

public class RoomsListFragment extends ListFragment {
    private MainActivity activity;

    public RoomsListFragment() {

    }

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState) {
        return super.onCreateView(inflater, container, savedInstanceState);
    }


    @Override
    public void onActivityCreated(Bundle savedInstanceState) {
        super.onActivityCreated(savedInstanceState);
        activity = (MainActivity) getActivity();

        //rooms(id, name, type)
        //room_types(id, type_name)
        Cursor c = activity.mDb.rawQuery("SELECT r.id, r.name, rt.type_name FROM rooms r INNER JOIN room_types rt ON r.type=rt.id", new String[]{});
        c.moveToFirst();
        int idIdx = c.getColumnIndex("id");
        int nameIdx = c.getColumnIndex("name");
        int typeIdx = c.getColumnIndex("type_name");
        List<String> rooms = new ArrayList<>();
        while (c.moveToNext()) {
            long id = c.getLong(idIdx);
            String name = c.getString(nameIdx);
            String type = c.getString(typeIdx);
            rooms.add(name + " (" + type + ")");
        }

        ListAdapter adapter = new ArrayAdapter<>(getActivity(),
                R.layout.rooms_layout_item_1, rooms.toArray());
        setListAdapter(adapter);
    }
}
