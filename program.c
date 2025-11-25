#include "program.h"

int program()
{
    droneport my_droneport ={0};
    my_droneport.initialized = false;
    my_droneport.dp_battery.initialized = false;
    server_connect client = {0};
    client.is_connected = false;

    start(&my_droneport);
    server_init(&client);

    while(1)
    {
        update_droneport(&my_droneport, &client);
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
    
    battery_init(&dp->dp_battery);

    dp->dp_status = 0;
    dp->initialized = true;
    printf("Система инициализирована...\n");
    
    return 0; 
}

void update_droneport(droneport *dp, server_connect *server)
{
    static int tick = 0;
    tick++;

    //programm_error();
    if(tick % 60 == 0)
    {
        battery_drainer(&dp->dp_battery);
    }

    if(tick % 10 == 0)
    {
        printf("[TICK: %d]\tDronePort status: %u\t|\tCharge: %d%%\t|\tBattery: %.1f mah\n", tick, dp->dp_status, dp->dp_battery.battery_charge_perc, dp->dp_battery.charge_level_mah);
    }

    if(tick % 30 == 0)
    {
        int com = server_command(server);
        printf("Команда от сервера No: %d\n\n", com);
        // if(com != 0)
        // {

        // }
    }
}