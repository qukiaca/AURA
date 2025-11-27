#include "command_processing.h"

void dron_charge(battery_unit *dronport, battery_unit *dron)
{
    if (dron->battery_charge_perc >= 100)
    {
        return;
    }
    
    if (dronport->charge_level_mah <= 100.0f)
    {
        return;
    }

    float charge_rate = 800.0f;
    
    if (charge_rate > dronport->charge_level_mah - 100.0f)
    {
        charge_rate = dronport->charge_level_mah - 100.0f;
    }
    
    float needed_charge = dron->capacity_mah - dron->charge_level_mah;
    if (charge_rate > needed_charge)
    {
        charge_rate = needed_charge;
    }

    float actual_charge = charge_rate * 0.85f;
    
    dronport->charge_level_mah -= charge_rate;
    dron->charge_level_mah += actual_charge;

    dronport->battery_charge_perc = (int)(dronport->charge_level_mah * 100.0f / dronport->capacity_mah);
    dron->battery_charge_perc = (int)(dron->charge_level_mah * 100.0f / dron->capacity_mah);
    
    if (dron->battery_charge_perc > 100) dron->battery_charge_perc = 100;
    if (dronport->battery_charge_perc < 0) dronport->battery_charge_perc = 0;
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
        } else {
            dron->flight_status = CHARGING;
            dron_charge(&dp->dp_battery, &dron->drone_battery);
        }
        break;
    
    case 1:
        if(dron->drone_battery.battery_charge_perc == 100)
        {
            dron->flight_status = IN_MISSION;
            dp->dp_status = DP_MISSION_ISSUED;
            dron->drone_battery.charge_level_mah *= 0.75f;
            dron->drone_battery.battery_charge_perc = 75;
        } else {
            printf("Миссия не может быть выполнена: дрон на зарядке...\n\n");
            dron_charge(&dp->dp_battery, &dron->drone_battery);
        }
        break;
        
    case 2:
        if(dron->drone_battery.battery_charge_perc == 100)
        {
            dron->flight_status = IN_MISSION;
            dp->dp_status = DP_MISSION_ISSUED;
            dron->drone_battery.charge_level_mah *= 0.50f;
            dron->drone_battery.battery_charge_perc = 50;
        } else {
            printf("Миссия не может быть выполнена: дрон на зарядке...\n\n");
            dron_charge(&dp->dp_battery, &dron->drone_battery);
        }
        break;
    
    case 3:
        if(dron->drone_battery.battery_charge_perc == 100)
        {
            dron->flight_status = IN_MISSION;
            dp->dp_status = DP_MISSION_ISSUED;
            dron->drone_battery.charge_level_mah *= 0.10f;
            dron->drone_battery.battery_charge_perc = 10;
        } else {
            printf("Миссия не может быть выполнена: дрон на зарядке...\n\n");
            dron_charge(&dp->dp_battery, &dron->drone_battery);
        }
        break;    
    case 4:
        if(dron->drone_battery.battery_charge_perc == 100)
        {
            dron->flight_status = IN_MISSION;
            dp->dp_status = DP_MISSION_ISSUED;
            dron->drone_battery.charge_level_mah *= 0.90f;
            dron->drone_battery.battery_charge_perc = 90;
        } else {
            printf("Миссия не может быть выполнена: дрон на зарядке...\n\n");
            dron_charge(&dp->dp_battery, &dron->drone_battery);
        }
        break;  
    case 5:
        if(dron->drone_battery.battery_charge_perc == 100)
        {
            dron->flight_status = IN_MISSION;
            dp->dp_status = DP_MISSION_ISSUED;
            dron->drone_battery.charge_level_mah *= 0.20f;
            dron->drone_battery.battery_charge_perc = 20;
        } else {
            printf("Миссия не может быть выполнена: дрон на зарядке...\n\n");
            dron_charge(&dp->dp_battery, &dron->drone_battery);
        }
        break;      
       
    case 6:
        if(dron->drone_battery.battery_charge_perc == 100)
        {
            dron->flight_status = IN_MISSION;
            dp->dp_status = DP_MISSION_ISSUED;
            dron->drone_battery.charge_level_mah *= 0.05f;
            dron->drone_battery.battery_charge_perc = 5;
        } else {
            printf("Миссия не может быть выполнена: дрон на зарядке...\n\n");
            dron_charge(&dp->dp_battery, &dron->drone_battery);
        }
        break;  
    case 7:
        if(dron->drone_battery.battery_charge_perc == 100)
        {
            dron->flight_status = IN_MISSION;
            dp->dp_status = DP_MISSION_ISSUED;
            dron->drone_battery.charge_level_mah *= 0.45f;
            dron->drone_battery.battery_charge_perc = 45;
        } else {
            printf("Миссия не может быть выполнена: дрон на зарядке...\n\n");
            dron_charge(&dp->dp_battery, &dron->drone_battery);
        }
        break;
        
    default:
        break;
    }
    
}