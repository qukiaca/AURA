#include "sample.h"

bool generated_id(char *uid)
{
    if(uid[0] == '\0')
    {
        char spinner[4] = {'-', '\\', '|', '/'};
        printf("UID отсутствует, идёт процесс генерации...\n");
        fflush(stdout);
        usleep(300000);

        for(int i = 0; i < 15; i++)
        {
            uid[i] = '0' + rand() % 10;
            printf("\r[%d/15]", i);
            for(int j = 0; j < 15; j++)
            {
                j<=i ? printf(".") : printf(" ");
            }
            printf("%c", spinner[i % 4]);
            fflush(stdout);
            usleep(200000);
        }
        uid[15] = '\0';
        if(uid[0] == '0') uid[0] = 'P';
        fflush(stdout);
        usleep(600000);
        printf("\r[15/15].........|ready\n");

        return true;
    }
    else
    {
        printf("Текущий UID: %s\n", uid);
        return false;
    }
    
}