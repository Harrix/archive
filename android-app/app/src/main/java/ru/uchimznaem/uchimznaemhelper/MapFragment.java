package ru.uchimznaem.uchimznaemhelper;


import android.content.Context;
import android.content.DialogInterface;
import android.os.Bundle;
import android.support.v4.app.Fragment;
import android.support.v7.app.AlertDialog;
import android.util.Log;
import android.util.TypedValue;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.Toast;

import ru.uchimznaem.uchimznaemhelper.entities.Floor;
import ru.uchimznaem.uchimznaemhelper.entities.Room;
import ru.uchimznaem.uchimznaemhelper.repository.MapRepository;
import ru.uchimznaem.uchimznaemhelper.repository.StubMapRepository;


/**
 * A simple {@link Fragment} subclass.
 */
public class MapFragment extends Fragment {

    private final Floor floor;
    private MapView map;
    //Rooms button
    Button roomsButton;



    public MapFragment() {
        // Required empty public constructor

        Bundle args = getArguments();
        Integer floorNumber = (args!=null) ? args.getInt("floor_id", 1) : 1;


        MapRepository repository = new StubMapRepository(getContext());
        this.floor = repository.getFloor(floorNumber);
    }


    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        // Inflate the layout for this fragment
        View v = inflater.inflate(R.layout.fragment_map, container, false);

        // added for testing
        Log.d("my", "Loading in MapFragment");

        //MapUtils.startLoadBuilding(getContext());
        final MapRepository repository = new StubMapRepository(getContext());
        Log.d("my", repository.getBuilding().toString());

        //todo передавать номер схемы в компоненту
        map = (MapView)v.findViewById(R.id.map);

        roomsButton = v.findViewById(R.id.button_rooms);
        roomsButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                final Context context = getContext();
                AlertDialog.Builder builderSingle = new AlertDialog.Builder(context);
                builderSingle.setIcon(R.drawable.icon_rooms);
                builderSingle.setTitle("Выберите помещение");

                final ArrayAdapter<Room> roomsAdapter = new ArrayAdapter<>(context, android.R.layout.select_dialog_item);
                //todo заполнить из объекта Floor

                for (Room room : repository.getFloor(1).getRooms()) {
                    roomsAdapter.add(room);
                }

                builderSingle.setNegativeButton("Отмена", new DialogInterface.OnClickListener() {
                    @Override
                    public void onClick(DialogInterface dialog, int which) {
                        dialog.dismiss();
                    }
                });


                builderSingle.setAdapter(roomsAdapter, new DialogInterface.OnClickListener() {
                    @Override
                    public void onClick(DialogInterface dialog, int position) {
                        //todo Обработать нажатие на выбранное помещение!

                        Room room = roomsAdapter.getItem(position);
                        Toast.makeText(context, room.toString(), Toast.LENGTH_LONG).show();
                        map.centerTo(room);
                    }
                });
                builderSingle.show();
            }
        });

        return v;
    }

}
