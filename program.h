#ifndef PROGRAM_H
#define PROGRAM_H

#include "struct.h"
#include "sample.h"
#include <string.h>

int start(int *pg_status, droneport *dp, drone_unit *drone);
void update_droneport(droneport *dp);

#endif