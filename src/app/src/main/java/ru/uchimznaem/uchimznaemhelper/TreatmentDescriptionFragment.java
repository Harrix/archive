package ru.uchimznaem.uchimznaemhelper;


import android.os.Bundle;
import android.support.v4.app.Fragment;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.TextView;


/**
 * A simple {@link Fragment} subclass.
 */
public class TreatmentDescriptionFragment extends Fragment {

    private TextView treatmentName, treatmentDescription;
    private ImageView image;

    private static final String TAG = "uz-helper";

    public TreatmentDescriptionFragment() {
        // Required empty public constructor
    }


    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        // Inflate the layout for this fragment
        View v = inflater.inflate(R.layout.fragment_room, container, false);

        String message = getArguments().getString("message");

        treatmentName = (TextView)v.findViewById(R.id.numberroom);
        image = (ImageView)v.findViewById(R.id.image);

        if (message.equals("hall")) {
            treatmentName.setText(message);
            image.setImageDrawable(getResources().getDrawable(R.drawable.room02));
        }

        if (message.equals("operating room")) {
            treatmentName.setText(message);
            image.setImageDrawable(getResources().getDrawable(R.drawable.room01));
        }


        return v;
    }
}
