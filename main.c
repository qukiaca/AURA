#include "struct.h"
#include "program.h"

#ifdef _WIN32
#include <windows.h>
#define SETUP_UTF8() SetConsoleOutputCP(CP_UTF8)
#else
#define SETUP_UTF8()
#endif

int main()
{
    SETUP_UTF8();
    srand(time(NULL));
    
    droneport my_droneport ={0};
    drone_unit my_drone = {0};

    my_droneport.initialized = false;
    my_drone.initialized = false;

    int pg_status = 0;  

    while(1)
    {
        if(!my_droneport.initialized || !my_drone.initialized)
        {
            start(&pg_status, &my_droneport, &my_drone);
        }
        else
        {
            update_droneport(&my_droneport);
        }
        sleep(1);
    }

    return pg_status;
}