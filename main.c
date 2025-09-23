#include "struct.h"
#include "program.h"
//#include <windows.h> // это только для винды также как и строки 7 и 8

int main()
{
    //SetConsoleOutputCP(CP_UTF8);
    //SetConsoleCP(CP_UTF8);

    srand(time(NULL));

    droneport my_droneport ={0};
    drone_unit my_drone = {0};

    my_droneport.initialized = false;
    my_drone.initialized = false;

    int pg_status = 0;  

    while(1)
    {
        if(my_droneport.initialized == false & my_drone.initialized == false)
        {
            start(&pg_status, &my_droneport, &my_drone);
        }
    }
    pg_status = 0;
    return pg_status;
}