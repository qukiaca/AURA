#include "dron.h"

bool dron_init(drone_unit *dron)
{
    if(dron->initialized == false)
    {
        printf("Проверка UID дрона...\n");
        if(generated_id(dron->uid))
        {
            printf("UID: %s сгенерирован и активирован\n", dron->uid);
        }

        dron->initialized = true;
    }
    dron_battery(&dron->drone_battery);
    return true;
}

void dron_battery(battery_unit *dron_batt)
{
    if(dron_batt == NULL)
    {
        return;
    }
    dron_batt->capacity_mah = DRON_BATTERY_CAPACITY_MAH;
    dron_batt->charge_level_mah = DRON_BATTERY_CAPACITY_MAH;
    dron_batt->battery_charge_perc = 100;
    dron_batt->battery_status = BATTERY_NORMAL;
    dron_batt->initialized = true;
}