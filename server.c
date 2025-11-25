#include "server.h"

bool server_init(server_connect *server)
{
    if(server->is_connected == false)
    {
        int a;
        do
        {
            a = rand() % 256;
        } while(a == 0 || a == 127);
        int b = rand() % 256;
        int c = rand() % 256;
        int d = 1 + rand() % 254;

        snprintf(server->ip_adress, 16, "%d.%d.%d.%d", a, b, c, d);

        server->port = 8000 + (rand() % 2000);
        printf("\nIP-адрес и порт сервера: %s:%d\n\n", server->ip_adress, server->port);

        server->is_connected = true;
        server->command_id = 0;
    }
    return true;
}

int server_command(server_connect *server)
{
    int command =  rand() % 8;
    return command;
}




// typedef struct
// {
//     char ip_adress[16]; // ip адрес
//     int port; // порт
//     bool is_connected; //подключён ли сервер или нет
//     time_t last_heartbeat; // время последнего пинга сервера
//     char last_command[128]; // последняя команда
//     bool command_acknowledged; // выполнил ли дрон эту команду
//     enum
//     {
//         CMD_NONE,
//         CMD_PHOTO_ZONE_A,
//         CMD_PHOTO_ZONE_B,
//         CMD_PHOTO_ZONE_C,
//         CMD_PHOTO_ZONE_D,
//         CMD_PHOTO_ZONE_E,
//         CMD_PHOTO_ZONE_F,
//         CMD_PHOTO_ZONE_G
//     } command_id; // айди команды
// }server_connect;