/*
** EPITECH PROJECT, 2021
** JSON-Parser
** File description:
** writer_element
*/

#include "parser.h"

static void writer_array(pars_data_t *data, int fd, int nb_tab)
{
    write_str(fd, "[");
    for (; data; data = data->next) {
        writer_value(data, fd, nb_tab);
        if (data->next)
            write_str(fd, ", ");
    }
    write_str(fd, "]");
}

static void writer_strings(pars_data_t *data, int fd)
{
    write_str(fd, "\"");
    write_str(fd, data->values.kstr);
    write_str(fd, "\"");
}

static void writer_number(pars_data_t *data, int fd)
{
    char str[64];

    snprintf(str, 64, "%d", data->values.kint);
    write_str(fd, str);
}

static void writer_float(pars_data_t *data, int fd)
{
    char str[64];

    snprintf(str, 64, "%f", data->values.kfloat);
    write_str(fd, str);
}

void writer_value(pars_data_t *data, int fd, int nb_tab)
{
    switch (data->type) {
    case (kint):
        writer_number(data, fd);
        break;
    case (kstr):
        writer_strings(data, fd);
        break;
    case (kfloat):
        writer_float(data, fd);
        break;
    case (kobj):
        if (data->values.kobj->data_name == NULL)
            writer_array(data->values.kobj, fd, nb_tab + 1);
        else
            write_data(data->values.kobj, fd, nb_tab + 1);
        break;
    case (knull):
        break;
    }
}
