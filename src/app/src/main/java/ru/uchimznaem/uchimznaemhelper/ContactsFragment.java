package ru.uchimznaem.uchimznaemhelper;

import android.content.Intent;
import android.database.Cursor;
import android.net.Uri;
import android.support.v4.app.Fragment;
import android.os.Bundle;
import android.support.v4.widget.SimpleCursorAdapter;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.AdapterView;
import android.widget.ImageView;
import android.widget.ListView;
import android.widget.TextView;

/**
 * @author ipetrushin, Vladimir Ulyanov
 */


public class ContactsFragment extends Fragment implements AdapterView.OnItemClickListener {

    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        int[] fields = new int[]{R.id.item_id, R.id.item_name, R.id.item_room};
        String[] headers = new String[]{"_id", "fullname", "phone"};

        View root = inflater.inflate(R.layout.fragment_contacts, container, false);
        ListView lvContacts = (ListView) root.findViewById(R.id.lvcontacts);
        MainActivity activity = (MainActivity) getActivity();
        Cursor c = activity.mDb.rawQuery("SELECT id AS _id, fullname, phone FROM person", null);
        SimpleCursorAdapter cursorAdapter = new SimpleCursorAdapter(activity, R.layout.contacts_item, c, headers, fields, SimpleCursorAdapter.FLAG_AUTO_REQUERY);
        lvContacts.setAdapter(cursorAdapter);
        lvContacts.setOnItemClickListener(this);
        return root;
    }


    @Override
    public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
        Bundle bundle = new Bundle();
        String phoneNumber = ((TextView)view.findViewById(R.id.item_room)).getText().toString();
        //String treatment = ((TextView)v.findViewById(R.id.item_name)).getText().toString();
        Intent intent = new Intent(Intent.ACTION_CALL, Uri.parse("tel:" + phoneNumber));
        startActivity(intent);
    }
}
