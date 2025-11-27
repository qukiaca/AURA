#ifndef DRON_H
#define DRON_H

#define DRON_BATTERY_CAPACITY_MAH 3850.0f

#include "struct.h"
#include "sample.h"

bool dron_init(drone_unit *dron);
void dron_battery(battery_unit *dron_batt);

#endif