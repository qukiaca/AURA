#include "random_errors.h"

int programm_error()
{
    int error_value = 1 + rand() % 100;

    if(error_value != 89)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}