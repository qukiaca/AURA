#ifndef COMMAND_PROCESSING_H
#define COMMAND_PROCESSING_H

#include "struct.h"

void dron_charge(battery_unit *dronport, battery_unit *dron);
void comm_process(droneport *dp, int command, drone_unit *dron);

#endif