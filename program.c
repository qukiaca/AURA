#include "program.h"
#include "random_errors.h"

int program()
{
    droneport my_droneport ={0};
    my_droneport.initialized = false;

    while(1)
    {
        if(!my_droneport.initialized)
        {
            start(&my_droneport);
        }
        else
        {
            update_droneport(&my_droneport);
        }
        sleep(1);
    }
}

int start(droneport *dp)
{
    printf("Проверка UID дронпорта...\n");
    if(generated_id(dp->uid))
    {
        printf("UID: %s сгенерирован и активирован\n", dp->uid);
    }
    
    accumulate(&dp->dp_battery);

    dp->dp_status = 0;
    dp->initialized = true;
    printf("Система инициализирована...\n");
    
    return 0; 
}

void update_droneport(droneport *dp)
{
    static int tick = 0;
    tick++;

    programm_error();

    if(tick % 10 == 0)
    {
        printf("[TICK: %d]\tDronePort status: %u\t|\tBattery: %d%%\n", tick, dp->dp_status, dp->dp_battery.battery_charge_perc);
    }
}