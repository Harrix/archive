package ru.uchimznaem.uchimznaemhelper.repository;

import ru.uchimznaem.uchimznaemhelper.entities.Building;
import ru.uchimznaem.uchimznaemhelper.entities.Floor;

/**
 * Реализация репозитория по получению информациюю о картах этажей здания
 * на основе ресурсов (информация подгружается из XML векторного представления
 */
public class ResourcesMapRepository implements MapRepository {
    @Override
    public Building getBuilding() {
        //todo
        return null;
    }

    @Override
    public Floor getFloor(int floorNumber) {
        //todo
        return null;
    }
}
