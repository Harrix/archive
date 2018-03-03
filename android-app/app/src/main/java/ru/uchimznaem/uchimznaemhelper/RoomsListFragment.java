package ru.uchimznaem.uchimznaemhelper;

import android.database.Cursor;
import android.os.Bundle;
import android.support.v4.app.ListFragment;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.ListAdapter;
import android.widget.ListView;

import java.util.ArrayList;

/**
 * @author Vladimir Ulyanov
 */

public class RoomsListFragment extends ListFragment {
    private MainActivity activity;
    private ArrayList<String> rooms;
    private ArrayList<String> roomTypes;
    private ArrayList<String> roomNames;

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
        rooms = new ArrayList<>();
        roomTypes = new ArrayList<>();
        roomNames = new ArrayList<>();

        while (c.moveToNext()) {
            long id = c.getLong(idIdx);
            String name = c.getString(nameIdx);
            roomNames.add(name);
            String type = c.getString(typeIdx);
            roomTypes.add(type);
            rooms.add(name + " (" + type + ")");
        }

        ListAdapter adapter = new ArrayAdapter<>(getActivity(),
                R.layout.list_layout_item_1, rooms.toArray());
        setListAdapter(adapter);
    }

    @Override
    public void onListItemClick(ListView l, View v, int position, long id) {
        RoomFragment fragment = new RoomFragment();
        Bundle bundle = new Bundle();
        bundle.putString("message", roomNames.get(position));
        bundle.putString("room_type", roomTypes.get(position));
        fragment.setArguments(bundle);
        activity.setFragment(fragment);
    }
}
