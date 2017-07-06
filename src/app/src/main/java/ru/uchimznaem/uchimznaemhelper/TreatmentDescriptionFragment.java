package ru.uchimznaem.uchimznaemhelper;


import android.database.Cursor;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.drawable.Drawable;
import android.os.Bundle;
import android.support.v4.app.Fragment;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.TextView;

import java.io.IOException;
import java.io.InputStream;


/**
 * A simple {@link Fragment} subclass.
 */
public class TreatmentDescriptionFragment extends Fragment {

    private TextView treatmentName, treatmentDescription, room;
    private ImageView image;

    private static final String TAG = "uz-helper";

    public TreatmentDescriptionFragment() {
        // Required empty public constructor
    }


    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        // Inflate the layout for this fragment
        View v = inflater.inflate(R.layout.fragment_treatment, container, false);
        image = (ImageView) v.findViewById(R.id.image);
        treatmentName = (TextView) v.findViewById(R.id.name);
        treatmentDescription = (TextView) v.findViewById(R.id.description);
        room = (TextView) v.findViewById(R.id.room);


        int id = Integer.parseInt(getArguments().getString("id"));
        //id = 1;
        MainActivity activity = (MainActivity) getActivity();
        Cursor c = activity.mDb.rawQuery("SELECT name, description, room, image_filename FROM treatment WHERE id = " + id, null);
        c.moveToFirst();

        if (c.getCount() > 0) {
            treatmentName.setText(c.getString(c.getColumnIndex("name")));
            treatmentDescription.setText(c.getString(c.getColumnIndex("description")));
            room.setText(c.getString(c.getColumnIndex("room")));
            String image_filename = c.getString(c.getColumnIndex("image_filename"));

            try {
                // loading image from filename
                InputStream is = activity.getAssets().open(image_filename);
                Bitmap bitmap = BitmapFactory.decodeStream(is);
                image.setImageBitmap(bitmap);

                treatmentName = (TextView) v.findViewById(R.id.numberroom);

            } catch (IOException e) {}

        }


        return v;
    }
}
