package ru.uchimznaem.uchimznaemhelper.repository;

import ru.uchimznaem.uchimznaemhelper.entities.Building;
import ru.uchimznaem.uchimznaemhelper.entities.Floor;

/**
 * @author Vladimir Ulyanov.
 *
 * Интерфейс репозитория для получения информации о здании,
 * прежде всего карты-схемы этажей.
 */

public interface MapRepository {

    /**
     * Получение информации о здании
     * @return объект, содержащий информацию о картах этажей здания
     */
    Building getBuilding();

    /**
     * Получение этажа по номеру
     * @param floorNumber номер этажа
     * @return Этаж, объект класса Floor
     */
    Floor getFloor(int floorNumber);
}
