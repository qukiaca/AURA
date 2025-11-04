#include "struct.h"

int main()
{
    SETUP_UTF8();
    srand(time(NULL));
    
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

    return 0;
}