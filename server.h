#ifndef SERVER_H
#define SERVER_H

#include "struct.h"

bool server_init(server_connect *server);
int server_command(server_connect *server);

#endif