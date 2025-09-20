#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int status = 0;
typedef struct
{
    char uid[16]; // идентификатор дрона

    bool is_connected; // подключён ли 0/1
    int battery_charge; // заряд батареи 0-100%

    float latitude; // широта
    float longitude; //долгота
    float altitude; // высота

    enum {
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
    char dp_uid[16];
    int dp_battery_charge;

    drone_unit drone;
    weather_station weather;
    // server структура сервера

    char log[256]; // логи
}droneport;


int main()
{
    int a = 0;
    while(1)
    {
        if(a==10)
        {
            status = 1;
        }
        a++;
        return status;
    }
    return status;
}