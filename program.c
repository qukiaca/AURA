#include "program.h"

int start(int *pg_status, droneport *dp, drone_unit *drone)
{
    printf("Проверка UID дронпорта...\n");
    if(generated_id(dp->uid))
    {
        printf("UID: %s сгенерирован и активирован\n", dp->uid);
    }
    
    printf("Проверка UID дрона...\n");
    if(generated_id(drone->uid))
    {
        printf("UID: %s сгенерирован и активирован\n", drone->uid);
    }


    //----------ПОКА ЧТО БУДЕТ ТАК, ПОТОМ РЕШУ КАК ПРАВИЛЬНО РЕАЛИЗОВАТЬ-------------//
    drone->drone_battery.capacity_mah = 2590;
    drone->drone_battery.max_voltage_v = 7.32;
    drone->drone_battery.min_voltage_v = 3.0;
    drone->drone_battery.current_voltage_v = 5.0;
    drone->drone_battery.current_ma = 4570;
    drone->drone_battery.charge_level_mah = drone->drone_battery.capacity_mah - 0;
    drone->drone_battery.battery_charge_perc = (drone->drone_battery.current_voltage_v - drone->drone_battery.min_voltage_v) * 100 / (drone->drone_battery.max_voltage_v - drone->drone_battery.min_voltage_v);
    drone->drone_battery.battery_status = BATTERY_NORMAL;
    drone->initialized = true;

    dp->dp_battery.capacity_mah = 50000;
    dp->dp_battery.max_voltage_v = 7.4;
    dp->dp_battery.min_voltage_v = 3.0;
    dp->dp_battery.current_voltage_v = 5.0;
    dp->dp_battery.current_ma = 5000;
    dp->dp_battery.charge_level_mah = dp->dp_battery.capacity_mah - 0;
    dp->dp_battery.battery_charge_perc = (dp->dp_battery.current_voltage_v - dp->dp_battery.min_voltage_v) * 100 / (dp->dp_battery.max_voltage_v - dp->dp_battery.min_voltage_v);
    dp->dp_battery.battery_status = BATTERY_NORMAL;
    dp->initialized = true;
    //---------------------------------------------------------------------------//

    printf("Система инициализирована...\n");
    
    return *pg_status; 
}

void update_droneport(droneport *dp)
{
    static int tick = 0;
    tick++;

    if(tick % 10 == 0)
    {
        printf("[TICK: %d]\tDronePort status: %u\t|\tBattery: %d%%\n", tick, dp->dp_status, dp->dp_battery.battery_charge_perc);
    }
}