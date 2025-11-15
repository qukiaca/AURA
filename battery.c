#include "battery.h"

void accumulate(droneport *batt)
{
    if(!battery_initializations(&batt)) accumulate(&batt);
}

static int battery_initializations(droneport *battery)
{
    battery->dp_battery
    dp->dp_battery.charge_level_mah = 25000;
    dp->dp_battery.battery_charge_perc = dp->dp_battery.charge_level_mah * 100 / dp->dp_battery.capacity_mah;
    dp->dp_battery.battery_status = 0;
}