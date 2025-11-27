#include "program.h"

int status_program = 0;

int program()
{
    droneport my_droneport = {0};
    my_droneport.initialized = false;
    my_droneport.dp_battery.initialized = false;
    server_connect client = {0};
    client.is_connected = false;
    drone_unit my_dron = {0};
    my_dron.initialized = false;

    start(&my_droneport);
    server_init(&client);
    dron_init(&my_dron);
    printf("Система инициализирована...\n\n");

    while(status_program == 0)
    {
        update_droneport(&my_droneport, &client, &my_dron);
        usleep(10000);
    }
    printf("\n\n\n\t\tДРОНПОРТ ВЗОРВАЛСЯ!!!\n\n\n");
    return status_program;
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
    
    return 0; 
}

void update_droneport(droneport *dp, server_connect *server, drone_unit *dron)
{
    if(dp->dp_battery.charge_level_mah <= 0)
    {
        status_program = 1;
        return;
    }
    static int tick = 0;
    tick++;

    //programm_error();
    if(tick % 60 == 0)
    {
        battery_drainer(&dp->dp_battery);
    }

    if(dron->flight_status == CHARGING && dron->drone_battery.battery_charge_perc < 100)
    {
        dron_charge(&dp->dp_battery, &dron->drone_battery);
    }

    if(tick % 10 == 0)
    {
        printf("[TICK: %d]\tDronePort status: %u\t|\tCharge: %d%%\t|\tBattery: %.1f mah\n", tick, dp->dp_status, dp->dp_battery.battery_charge_perc, dp->dp_battery.charge_level_mah);
        printf("Drone status: %d |\tDrone charge: %d%%\n", dron->flight_status, dron->drone_battery.battery_charge_perc);
    }

    if(tick % 30 == 0)
    {
        int com = server_command(server);
        printf("Команда от сервера No: %d\n\n", com);
        comm_process(dp, com, dron);  // Убрал & - передаем указатели, а не двойные указатели
    }
}