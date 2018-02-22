package ru.uchimznaem.uchimznaemhelper;


import android.content.Context;
import android.content.DialogInterface;
import android.os.Bundle;
import android.support.v4.app.Fragment;
import android.support.v7.app.AlertDialog;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.Toast;


/**
 * A simple {@link Fragment} subclass.
 */
public class MapFragment extends Fragment {

    private ImageView map;
    private ImageView button_floor_1;
    private ImageView button_floor_2;
    private ImageView button_floor_3;
    private ImageView button_floor_4;

    //Rooms button
    Button roomsButton;



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

        roomsButton = v.findViewById(R.id.button_rooms);
        roomsButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                final Context context = getContext();
                AlertDialog.Builder builderSingle = new AlertDialog.Builder(context);
                builderSingle.setIcon(R.drawable.icon_rooms);
                builderSingle.setTitle("Выберите помещение");

                final ArrayAdapter<String> roomsAdapter = new ArrayAdapter<String>(context, android.R.layout.select_dialog_item);
                roomsAdapter.add("Процедурный кабинет №7");
                roomsAdapter.add("Столовая");
                roomsAdapter.add("Палата №1");
                roomsAdapter.add("Палата №2");
                roomsAdapter.add("Палата №3");

                builderSingle.setNegativeButton("cancel", new DialogInterface.OnClickListener() {
                    @Override
                    public void onClick(DialogInterface dialog, int which) {
                        dialog.dismiss();
                    }
                });


                builderSingle.setAdapter(roomsAdapter, new DialogInterface.OnClickListener() {
                    @Override
                    public void onClick(DialogInterface dialog, int position) {
                        //todo Обработать нажатие на выбранное помещение!

                        String room = roomsAdapter.getItem(position);
                        Toast.makeText(context, room, Toast.LENGTH_LONG).show();
                    }
                });
                builderSingle.show();
            }
        });

        return v;
    }

}
