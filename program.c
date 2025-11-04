#include "program.h"

int start(droneport *dp)
{
    printf("Проверка UID дронпорта...\n");
    if(generated_id(dp->uid))
    {
        printf("UID: %s сгенерирован и активирован\n", dp->uid);
    }
    
    dp->initialized = true;
    printf("Система инициализирована...\n");
    
    return 0; 
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