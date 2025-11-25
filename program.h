#ifndef PROGRAM_H
#define PROGRAM_H

#include <string.h>

#include "struct.h"
#include "random_errors.h"
#include "sample.h"
#include "battery.h"
#include "server.h"


int program();
int start(droneport *dp);
void update_droneport(droneport *dp, server_connect *server);

#endif