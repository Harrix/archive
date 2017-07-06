package ru.uchimznaem.uchimznaemhelper;

import android.content.Intent;
import android.content.pm.PackageManager;
import android.database.Cursor;
import android.net.Uri;
import android.support.v4.app.ActivityCompat;
import android.support.v4.app.Fragment;
import android.os.Bundle;
import android.support.v4.content.ContextCompat;
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

    private static final int MY_PERMISSIONS_REQUEST_CALL_PHONE = 0x000000;

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
        // Here, thisActivity is the current activity
        if (ContextCompat.checkSelfPermission(getContext(), android.Manifest.permission.CALL_PHONE)
                != PackageManager.PERMISSION_GRANTED) {

            ActivityCompat.requestPermissions(getActivity(),
                    new String[]{android.Manifest.permission.CALL_PHONE},
                    MY_PERMISSIONS_REQUEST_CALL_PHONE);

            // MY_PERMISSIONS_REQUEST_CALL_PHONE is an
            // app-defined int constant. The callback method gets the
            // result of the request.
        } else {
            //You already have permission
            try {
                startActivity(intent);
            } catch(SecurityException e) {
                e.printStackTrace();
            }
        }
        startActivity(intent);
    }

    @Override
    public void onRequestPermissionsResult(int requestCode,
                                           String permissions[], int[] grantResults) {
        switch (requestCode) {
            case MY_PERMISSIONS_REQUEST_CALL_PHONE: {
                // If request is cancelled, the result arrays are empty.
                if (grantResults.length > 0
                        && grantResults[0] == PackageManager.PERMISSION_GRANTED) {

                    // permission was granted, yay! Do the phone call

                } else {

                    // permission denied, boo! Disable the
                    // functionality that depends on this permission.
                }
                return;
            }

            // other 'case' lines to check for other
            // permissions this app might request
        }
    }
}
