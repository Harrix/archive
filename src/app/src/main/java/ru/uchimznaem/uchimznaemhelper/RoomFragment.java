package ru.uchimznaem.uchimznaemhelper;


import android.os.Bundle;
import android.support.v4.app.Fragment;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.TextView;


/**
 * A simple {@link Fragment} subclass.
 */
public class RoomFragment extends Fragment {

    private TextView numberRoom;
    private TextView description;
    private ImageView image;
    private ImageView map;

    private static final String TAG = "uz-helper";

    public RoomFragment() {
        // Required empty public constructor
    }


    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        // Inflate the layout for this fragment
        View v = inflater.inflate(R.layout.fragment_room, container, false);

        String message = getArguments().getString("message");

        numberRoom = (TextView)v.findViewById(R.id.numberroom);
        description = (TextView)v.findViewById(R.id.description);
        image = (ImageView)v.findViewById(R.id.image);
        map = (ImageView)v.findViewById(R.id.map);

        if (message.equals("hall")) {
            numberRoom.setText("Холл");
            image.setImageDrawable(getResources().getDrawable(R.drawable.room02));
            map.setImageDrawable(getResources().getDrawable(R.drawable.map02));
            description.setText("Здесь вас встретят и ответят на вопросы.");
        }

        if (message.equals("operating room")) {
            numberRoom.setText("Операционная");
            image.setImageDrawable(getResources().getDrawable(R.drawable.room01));
            map.setImageDrawable(getResources().getDrawable(R.drawable.map01));
            description.setText("Кабинет 101. Находится на 2 этаже. В ней проходят операции общего характера.");
        }


        return v;
    }
}
