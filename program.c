#include "program.h"

int start(int *pg_status, droneport *dp, drone_unit *drone)
{
    if(dp->uid[0] == '\0')
    {
        printf("UID дронпорта отсутствует, процесс генерации...\n");
        fflush(stdout);
        usleep(300000);

        for(int i = 0; i < 15; i++)
        {
            dp->uid[i] = '0' + rand() % 10;
            printf("\r[%d/15]", i);
            fflush(stdout);
            usleep(300000);
        }
        dp->uid[15] = '\0';
        if(dp->uid[0] == '0') dp->uid[0] = 'P';
        fflush(stdout);
        usleep(600000);
        printf("\r[15/15]");
        printf("\nUID дронпорта успешно сгенерирован! Сгенерировайнный UID: %s\n", dp->uid);
    }

    if(drone->uid[0] == '\0')
    {
        printf("\n\n\nUID дрона отсутствует, процесс генерации...\n");
        fflush(stdout);
        usleep(600000);

        for(int i = 0; i < 15; i++)
        {
            drone->uid[i] = '0' + rand() % 10;
            printf("\r[%d/15]", i);
            fflush(stdout);
            usleep(600000);
        }
        drone->uid[15] = '\0';
        if(drone->uid[0] == '0') drone->uid[0] = 'D';
        fflush(stdout);
        usleep(1000000);
        printf("\r[15/15]");
        printf("\nUID дрона успешно сгенерирован! Сгенерировайнный UID: %s\n", drone->uid);
    }

    return *pg_status; 
}
