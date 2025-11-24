#include "battery.h"

void battery_init(battery_unit *batt)
{
    if (batt == NULL)
    {
        return;
    }
    batt->capacity_mah = DP_BATTERY_CAPACITY_MAH;
    batt->charge_level_mah = DP_BATTERY_CAPACITY_MAH;
    batt->battery_charge_perc = 100;
    batt->battery_status = BATTERY_NORMAL;
    batt->initialized = true;
    
}

void battery_drainer(battery_unit *batt)
{
    if (batt == NULL) {
        return;
    }

    if(!batt->initialized || batt->capacity_mah <= 0)
    {
        battery_init(batt);
    }
    else
    {
        float drain = DP_BATTERY_DRAIN_MIN + ((float)rand() / RAND_MAX) * (DP_BATTERY_DRAIN_MAX - DP_BATTERY_DRAIN_MIN);

        batt->charge_level_mah -= drain;
        if(batt->charge_level_mah < 0) batt->charge_level_mah = 0;

        batt->battery_charge_perc = (int)(batt->charge_level_mah * 100.0f / batt->capacity_mah);
    }

}
