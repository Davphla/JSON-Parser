/*
** EPITECH PROJECT, 2022
** JSON-Parser
** File description:
** TODO: add description
*/

#include "checker.h"
#include <stdio.h>

void json_whitespace(FILE *fd)
{
    fscanf(fd, "%[ \n\r\t]");
}

extern json_content_t *json_read(const char *filepath)
{
    FILE *fd = fopen(filepath, "r");

    fclose(fd);
}
