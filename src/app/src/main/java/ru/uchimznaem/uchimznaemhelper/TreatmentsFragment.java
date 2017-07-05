package ru.uchimznaem.uchimznaemhelper;

import android.database.Cursor;
import android.os.Bundle;
import android.support.v4.app.Fragment;
import android.support.v4.widget.SimpleCursorAdapter;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.AdapterView;
import android.widget.ListAdapter;
import android.widget.ListView;
import android.widget.TextView;

/**
 * @author Vladimir Ulyanov
 */


public class TreatmentsFragment extends Fragment implements AdapterView.OnItemClickListener {

    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        int[] fields = new int[]{R.id.item_id, R.id.item_name, R.id.item_room};
        String[] headers = new String[]{"_id", "name", "room"};

        View root = inflater.inflate(R.layout.fragment_contacts, container, false);
        ListView lvContacts = (ListView) root.findViewById(R.id.lvcontacts);
        lvContacts.setOnItemClickListener(this);
        MainActivity activity = (MainActivity) getActivity();
        //Cursor c = activity.mDb.rawQuery("SELECT * FROM person", null);
        Cursor c = activity.mDb.rawQuery("SELECT id AS _id, name, '(кабинет №' ||room||')' as room FROM treatment", null);
        SimpleCursorAdapter cursorAdapter = new SimpleCursorAdapter(activity, R.layout.treatments_item, c, headers, fields, SimpleCursorAdapter.FLAG_AUTO_REQUERY);
        lvContacts.setAdapter(cursorAdapter);
        return root;
    }


    @Override
    public void onItemClick(AdapterView<?> l, View v, int position, long id) {
        SimpleCursorAdapter adapter = (SimpleCursorAdapter) l.getAdapter();
        String data = ((TextView)v.findViewById(R.id.item_name)).getText().toString(); //todo
        RoomFragment fragment = new RoomFragment();
        Bundle bundle = new Bundle();
        bundle.putString("message", data);
        fragment.setArguments(bundle);
        ((MainActivity)getActivity()).setFragment(fragment);
    }
}
