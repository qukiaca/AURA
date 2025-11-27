#ifndef BATTERY_H
#define BATTERY_H

#include "struct.h"

#define DP_BATTERY_CAPACITY_MAH 25000.0f
#define DP_BATTERY_DRAIN_MIN 150.0f
#define DP_BATTERY_DRAIN_MAX 250.0f

void battery_init(battery_unit *batt);
void battery_drainer(battery_unit *batt);

#endif