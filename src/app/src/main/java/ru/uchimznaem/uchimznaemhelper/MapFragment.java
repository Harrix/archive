package ru.uchimznaem.uchimznaemhelper;


import android.os.Bundle;
import android.support.v4.app.Fragment;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;


/**
 * A simple {@link Fragment} subclass.
 */
public class MapFragment extends Fragment {

    private ImageView map;
    private ImageView button_floor_1;
    private ImageView button_floor_2;
    private ImageView button_floor_3;
    private ImageView button_floor_4;


    public MapFragment() {
        // Required empty public constructor
    }


    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        // Inflate the layout for this fragment
        View v = inflater.inflate(R.layout.fragment_map, container, false);

        map = (ImageView)v.findViewById(R.id.map);

        button_floor_1 = (ImageView)v.findViewById(R.id.button_floor_1);
        button_floor_1.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                map.setImageDrawable(getResources().getDrawable(R.drawable.floor01));
            }
        });

        button_floor_2 = (ImageView)v.findViewById(R.id.button_floor_2);
        button_floor_2.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                map.setImageDrawable(getResources().getDrawable(R.drawable.floor02));
            }
        });

        button_floor_3 = (ImageView)v.findViewById(R.id.button_floor_3);
        button_floor_3.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                map.setImageDrawable(getResources().getDrawable(R.drawable.floor03));
            }
        });

        button_floor_4 = (ImageView)v.findViewById(R.id.button_floor_4);
        button_floor_4.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                map.setImageDrawable(getResources().getDrawable(R.drawable.floor04));
            }
        });

        return v;
    }

}
