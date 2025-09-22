#ifndef STRUCT_H
#define STRUCT_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
    int battery_charge_perc; // процент заряда 0-100%
    float capacity_mah; // ёмкость батареи в Mah
    float voltage_mv; // вольтаж
    float current_ma; // ток потребления
    float charge_level_mah; // текущий заряд

    enum
    {
        BATTERY_NORMAL,
        BATTERY_CHARGING,
        BATTERY_DISCHARGING,
        BATTERY_CRITICAL,
        BATTERY_FAILURE
    }battery_status;

}battery_unit;

typedef struct
{
    char uid[16]; // идентификатор дрона

    bool is_connected; // подключён ли 0/1

    float latitude; // широта
    float longitude; //долгота
    float altitude; // высота

    battery_unit drone_battery;

    enum 
    {
        DISARMED, ARMING,
        ARMED, TAKING_OFF,
        IN_MISSION, LANDING,
        ERROR
    } flight_status; // статус дрона
}drone_unit;

typedef struct
{
    float temperature;
    float humidity;
    float wind_speed;
    bool is_raining;
}weather_station;


typedef struct
{

}server;

typedef struct
{
    char uid[16];

    battery_unit dp_battery;

    drone_unit drone;
    weather_station weather;
    // server структура сервера

    char log[256]; // логи
}droneport;

#endif