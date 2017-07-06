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
        String roomType = getArguments().getString("room_type");
        if (roomType == null) roomType = "";

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
        else if (message.equals("operating room") || roomType.equals("Операционная")) {
            numberRoom.setText("Операционная");
            image.setImageDrawable(getResources().getDrawable(R.drawable.room01));
            map.setImageDrawable(getResources().getDrawable(R.drawable.map01));
            description.setText("Операционная находится на 2 этаже. В ней проходят операции общего характера.");
        }
        else if (roomType.equals("Палата")){
            numberRoom.setText(message);
            image.setImageDrawable(getResources().getDrawable(R.drawable.room00));
            map.setImageDrawable(getResources().getDrawable(R.drawable.map01));
            description.setText(message+" находится на 3 этаже и представляет собой стерильный бокс. В ней живут пациенты и их родители.");
        }
        else if (roomType.equals("Учебная аудитория")){
            numberRoom.setText(message);
            image.setImageDrawable(getResources().getDrawable(R.drawable.room02));
            map.setImageDrawable(getResources().getDrawable(R.drawable.map02));
            description.setText("Учебная аудитория "+message+" находится на 4 этаже и представляет собой учебный класс с самой современной техникой и методическими материалами. В ней регулярно проходят занятия по робототехнике и запись радио-передач.");
        }
        else if (roomType.equals("Столовая")){
            numberRoom.setText(message);
            image.setImageDrawable(getResources().getDrawable(R.drawable.room02));
            map.setImageDrawable(getResources().getDrawable(R.drawable.map02));
            description.setText(message+" находится на 1 этаже и обеспечивает качественной и безопасной пищей всех обитателей школы, включая детей, их родителей, учителей и мединских работников. ");
        }
        else if (roomType.equals("Врачебный кабинет")){
            numberRoom.setText(message);
            image.setImageDrawable(getResources().getDrawable(R.drawable.room00));
            map.setImageDrawable(getResources().getDrawable(R.drawable.map00));
            description.setText(message+" находится на 7 этаже и предназначен для проведения осмотров, терапевтических сеансов и других медицинских процедур. ");
        }
        else if (roomType.equals("Процедурный кабинет")){
            numberRoom.setText(message);
            image.setImageDrawable(getResources().getDrawable(R.drawable.room00));
            map.setImageDrawable(getResources().getDrawable(R.drawable.map00));
            description.setText(message+" находится на 3 этаже и оборудован техникой для проведения физио-процедур. ");
        }
        else if (roomType.equals("Диагностический кабинет")){
            numberRoom.setText(message);
            image.setImageDrawable(getResources().getDrawable(R.drawable.room00));
            map.setImageDrawable(getResources().getDrawable(R.drawable.map00));
            description.setText(message+" находится на 2 этаже и оборудован техникой для проведения радиологической диагностики. ");
        }
        else {
            numberRoom.setText(message);
            image.setImageDrawable(getResources().getDrawable(R.drawable.room00));
            map.setImageDrawable(getResources().getDrawable(R.drawable.map00));
            description.setText("Кабинет.");
        }

        return v;
    }
}
