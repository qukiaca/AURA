#ifndef CONFIG_H
#define CONFIG_H

#include "struct.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cJSON.h"

#define CONFIG_FILE "config.json"

void config_set_uid(const char *uid);
void config_set_ip(const char *ip);
void config_set_port(const char *port);
char *config_get_uid();
char *config_get_ip();
char *config_get_port();

#endif