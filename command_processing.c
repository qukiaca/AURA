#include "command_processing.h"



static void dron_charge(battery_unit *dronport, battery_unit *dron)
{
    if(dron->battery_charge_perc >= 100 || dronport->charge_level_mah <= 0)
    {
        return;
    }

    float charge_rate = dron->charge_level_mah * 0.5f;
    float actual_charge = charge_rate;
    
    if(actual_charge > dronport->charge_level_mah)
    {
        actual_charge = dronport->charge_level_mah;
    }

    if(actual_charge > dron->capacity_mah - dron->charge_level_mah)
    {
        actual_charge = dron->capacity_mah - dron->charge_level_mah;
    }

    float received_charge = actual_charge * 0.9f;

    dronport->charge_level_mah -= actual_charge;
    dron->charge_level_mah += received_charge;

    dronport->battery_charge_perc = (int)(dronport->charge_level_mah * 100.0f / dronport->capacity_mah);
    dron->battery_charge_perc = (int)(dron->charge_level_mah * 100.0f / dron->capacity_mah);
}

void comm_process(droneport *dp, int command, drone_unit *dron)
{
    switch (command)
    {
    case 0:
    dp->dp_status = DP_IDLE;
    if(dron->drone_battery.battery_charge_perc == 100)
    {
        dron->flight_status = DOCKED;
    }else{
        dron->flight_status = CHARGING;
    }
    break;
    
    case 1:
        if(dron->drone_battery.battery_charge_perc == 100)
        {
            dron->flight_status = IN_MISSION;
            dp->dp_status = DP_MISSION_ISSUED;
            dron->drone_battery.battery_charge_perc *= 0.75;
        }
        else{
            dron_charge(&dp->dp_battery, &dron->drone_battery);
        }
        break;
    
    case 2:
        if(dron->drone_battery.battery_charge_perc == 100)
        {
            dron->flight_status = IN_MISSION;
            dp->dp_status = DP_MISSION_ISSUED;
            dron->drone_battery.battery_charge_perc *= 0.50;
        }
        else{
            dron_charge(&dp->dp_battery, &dron->drone_battery);
        }
        break;
        

    case 3:
        if(dron->drone_battery.battery_charge_perc == 100)
        {
            dron->flight_status = IN_MISSION;
            dp->dp_status = DP_MISSION_ISSUED;
            dron->drone_battery.battery_charge_perc *= 0.25;
        }
        else{
            dron_charge(&dp->dp_battery, &dron->drone_battery);
        }
        break;
        
    case 4:
        if(dron->drone_battery.battery_charge_perc == 100)
        {
            dron->flight_status = IN_MISSION;
            dp->dp_status = DP_MISSION_ISSUED;
            dron->drone_battery.battery_charge_perc *= 0.45;
        }
        else{
            dron_charge(&dp->dp_battery, &dron->drone_battery);
        }
        break;
    
    case 5:
        if(dron->drone_battery.battery_charge_perc == 100)
        {
            dron->flight_status = IN_MISSION;
            dp->dp_status = DP_MISSION_ISSUED;
            dron->drone_battery.battery_charge_perc *= 0.90;
        }
        else{
            dron_charge(&dp->dp_battery, &dron->drone_battery);
        }
        break;
        
    case 6:
        if(dron->drone_battery.battery_charge_perc == 100)
        {
            dron->flight_status = IN_MISSION;
            dp->dp_status = DP_MISSION_ISSUED;
            dron->drone_battery.battery_charge_perc *= 0.15;
        }
        else{
            dron_charge(&dp->dp_battery, &dron->drone_battery);
        }
        break;
            
    case 7:
        if(dron->drone_battery.battery_charge_perc == 100)
        {
            dron->flight_status = IN_MISSION;
            dp->dp_status = DP_MISSION_ISSUED;
            dron->drone_battery.battery_charge_perc *= 0.5;
        }
        else{
            dron_charge(&dp->dp_battery, &dron->drone_battery);
        }
        break;
    
    }
}