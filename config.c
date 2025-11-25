#include "config.h"

static cJSON *load_or_create_config()
{
    FILE *fp = fopen(CONFIG_FILE, "r");
    if(!fp)
    {
        return cJSON_CreateObject();
    }

    fseek(fp, 0, SEEK_END);
    long len = ftell(fp);
    rewind(fp);

    char *buf = (char*)malloc(len + 1);
    if(!buf)
    {
        fclose(fp);
        return cJSON_CreateObject();
    }

    fread(buf, 1, len, fp);
    buf[len] = '\0';
    fclose(fp);

    cJSON *root = cJSON_Parse(buf);
    free(buf);
}

static void save_config(cJSON *root)
{
    char *json_str = cJSON_PrintUnformatted(root);
    if(!json_str) return;

    FILE *fp = fopen(CONFIG_FILE, "w");
    if(fp)
    {
        fputs(json_str, fp);
        fclose(fp);
    }
    cJSON_free(json_str);
}

void config_set_uid(const char *uid)
{
    cJSON *root = load_or_create_config();
    cJSON *uid_obj = cJSON_GetObjectItemCaseSensitive(root, "uid");
    if(uid_obj)
    {
        cJSON_SetValuestring(uid_obj, uid);
    } else {
        cJSON_AddStringToObject(root, "uid", uid);
    }
    save_config(root);
    cJSON_Delete(root);
}

void config_set_ip(const char *ip)
{
    cJSON *root = load_or_create_config();
    cJSON *ip_obj = cJSON_GetObjectItemCaseSensitive(root, "ip");
    if(ip_obj)
    {
        cJSON_SetValuestring(ip_obj, ip);
    } else {
        cJSON_AddStringToObject(root, "ip", ip);
    }
    save_config(root);
    cJSON_Delete(root);
}

void config_set_port(const char *port)
{
    cJSON *root = load_or_create_config();
    cJSON *port_obj = cJSON_GetObjectItemCaseSensitive(root, "port");
    if(port_obj)
    {
        cJSON_SetValuestring(port_obj, port);
    } else {
        cJSON_AddStringToObject(root, "port", port);
    }
    save_config(root);
    cJSON_Delete(root);
}

char *config_get_uid()
{
    cJSON *root = load_or_create_config();
    cJSON *uid_obj = cJSON_GetObjectItemCaseSensitive(root, "uid");
    char *result = NULL;
    if(cJSON_IsString(uid_obj))
    {
        result = strdup(uid_obj->valuestring);
    }
    cJSON_Delete(root);
    return result;
}

char *config_get_ip()
{
    cJSON *root = load_or_create_config();
    cJSON *ip_obj = cJSON_GetObjectItemCaseSensitive(root, "ip");
    char *result = NULL;
    if(cJSON_IsString(ip_obj))
    {
        result = strdup(ip_obj->valuestring);
    }
    cJSON_Delete(root);
    return result;
}

char *config_get_port()
{
    cJSON *root = load_or_create_config();
    cJSON *port_obj = cJSON_GetObjectItemCaseSensitive(root, "port");
    char *result = NULL;
    if(cJSON_IsString(port_obj))
    {
        result = (int)(port_obj->valuedouble);
    }
    cJSON_Delete(root);
    return result;
}