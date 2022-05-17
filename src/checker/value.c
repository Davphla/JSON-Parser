/*
** EPITECH PROJECT, 2022
** JSON-Parser
** File description:
** TODO: add description
*/

#include "checker.h"
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <err.h>

long json_number(FILE *fd)
{
    long nb = 0;
    char begin[128];
    char *end;

    fgets(begin, 128, fd);
    nb = strtol(begin, &end, 0);
    if (nb == 0 && errno)
        warn("Invalid conversion at %ld\n", ftell(fd));
    return nb;
}
