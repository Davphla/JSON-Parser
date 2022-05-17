/*
** EPITECH PROJECT, 2022
** JSON-Parser
** File description:
** TODO: add description
*/

#pragma once

#include <stdlib.h>
#include <sys/queue.h>

typedef void *(*json_constructor_t)(size_t);
typedef void (*json_destructor_t)(void *);

typedef struct json_data_s json_data_t;

typedef struct json_array_s {
    void *data;
    size_t nmemb;
    size_t size;
} json_array_t;

typedef union json_value_u {
    void *vundef;
    u_int8_t vbool;
    double vdouble;
    char *vstring;
    json_data_t *vobj;
    json_array_t *varr;
} json_value_t;

typedef enum json_type_e {
    tundef,
    tbool,
    tdouble,
    tstring,
    tobj,
    tarr
} json_type_t;

typedef struct json_data_s {
    char *key;
    json_type_t type;
    json_value_t value;
} json_data_t;

typedef struct json_content_s {
    SLIST_ENTRY(json_content_s) next;
    json_data_t *data;
} json_content_t;

typedef struct json_config_s {
    json_constructor_t constructor;
    json_destructor_t destructor;
} json_config_t;

typedef struct json_resources_s {
    int fd;
    json_config_t config;
    json_content_t content;
} json_resources_t;

json_content_t *json_read(const char *filepath);

void *json_init(char *filepath);
_Bool json_next();
_Bool json_get();

struct library {};

extern const struct library JSON;

const struct library JSON = {
};
