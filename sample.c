#include "sample.h"

bool generated_id(char *uid)
{
    if(uid[0] == '\0')
    {
        printf("UID отсутствует, идёт процесс генерации...\n");
        fflush(stdout);
        usleep(300000);

        for(int i = 0; i < 15; i++)
        {
            uid[i] = '0' + rand() % 10;
            printf("\r[%d/15]", i);
            fflush(stdout);
            usleep(300000);
        }
        uid[15] = '\0';
        if(uid[0] == '0') uid[0] = 'P';
        fflush(stdout);
        usleep(600000);
        printf("\r[15/15]\n");

        return true;
    }
    else
    {
        printf("Текущий UID: %s\n", uid);
        return false;
    }
    
}