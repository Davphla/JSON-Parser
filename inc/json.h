/*
** EPITECH PROJECT, 2022
** JSON-Parser
** File description:
** TODO: add description
*/

#pragma once

typedef unsigned long json_size_t;

typedef void *(*json_constructor_t)(json_size_t);
typedef void (*json_destructor_t)(void *);

typedef struct json_config_s {
    json_constructor_t constructor;
    json_destructor_t destructor;
} json_config_t;

typedef struct json_resources_s {
    json_config_t config;
    int fd;
} json_resources_t;

void *json_init(char *filepath);
_Bool json_next();
_Bool json_read();
_Bool json_get();

struct library {};

extern const struct library JSON;

const struct library JSON = {
};
