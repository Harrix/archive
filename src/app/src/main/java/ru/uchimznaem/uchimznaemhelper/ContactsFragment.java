package ru.uchimznaem.uchimznaemhelper;

import android.database.Cursor;
import android.support.v4.app.Fragment;
import android.os.Bundle;
import android.support.v4.widget.SimpleCursorAdapter;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ListView;

/**
 * @author ipetrushin
 */


public class ContactsFragment extends Fragment {

    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        int[] fields = new int[]{R.id.item_id, R.id.item_name, R.id.item_room, R.id.listphone};
        String[] headers = new String[]{"_id", "fullname", "room_number", "phone"};

        View root = inflater.inflate(R.layout.fragment_contacts, container, false);
        ListView lvContacts = (ListView) root.findViewById(R.id.lvcontacts);
        MainActivity activity = (MainActivity) getActivity();
        Cursor c = activity.mDb.rawQuery("SELECT id AS _id, fullname, room_number, phone FROM person", null);
        SimpleCursorAdapter cursorAdapter = new SimpleCursorAdapter(activity, R.layout.contacts_item, c, headers, fields, SimpleCursorAdapter.FLAG_AUTO_REQUERY);
        lvContacts.setAdapter(cursorAdapter);
        return root;
    }
}
