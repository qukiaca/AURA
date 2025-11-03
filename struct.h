#ifndef STRUCT_H
#define STRUCT_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>
#include "cJSON.h"

typedef struct
{
    int battery_charge_perc; // процент заряда 0-100%
    float capacity_mah; // ёмкость батареи в Mah
    float current_voltage_v; // текущее напряжение
    float max_voltage_v; // максимальный порог напряжения
    float min_voltage_v; // минимальный порог напряжения
    float current_ma; // ток потребления
    float charge_level_mah; // текущий заряд

    enum
    {
        BATTERY_NORMAL, // норма
        BATTERY_CHARGING, // зарядка
        BATTERY_DISCHARGING, //разрядка
        BATTERY_CRITICAL, // критическое состояние, или ошибка
        BATTERY_FAILURE // пизда аккуму
    }battery_status;

}battery_unit;

typedef struct
{
    char uid[16]; // идентификатор дрона

    bool initialized; // временная переменная. когда дополню все инициализации тогда удалю

    bool is_connected; // подключён ли 0/1

    float latitude; // широта
    float longitude; //долгота
    float altitude; // высота

    battery_unit drone_battery;

    enum 
    {
        DISARMED,
        ARMING,
        ARMED,
        TAKING_OFF,
        IN_MISSION, // выполнение задания
        LANDING,
        ERROR, // ошибка
        DOCKING, // на посадке в док-станцию
        CHARGING // заряжается
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
    char ip_adress[16]; // ip адрес
    int port; // порт
    bool is_connected; //подключён ли сервер или нет
    time_t last_heartbeat; // время последнего пинга сервера
    char last_command[128]; // последняя команда
    bool command_acknowledged; // выполнил ли дрон эту команду
    int command_id; // айди команды
}server_connect;

typedef struct
{
    char uid[16];

    bool initialized; // тоже временная переменная

    battery_unit dp_battery;
    drone_unit drone;
    weather_station weather;
    server_connect server;

    bool override_safety; //игнорирование всех ограничей если всё пошло по пизде

    char log[256]; // логи
    time_t last_event_time; // время последней команды

    enum
    {
        DP_IDLE, // ожидание команд
        DP_CHARGING_DRONE, // зарядка дрона
        DP_SENDING_TELEMETRY, // отправка данных серверу
        DP_ERROR // ошибка
    }dp_status;
}droneport;

#endif