/*
** EPITECH PROJECT, 2021
** JSON-Parser
** File description:
** main_writer
*/

#include "parser.h"

static void writer_data_name(pars_data_t *data, int fd, int nb_tab)
{
    write_tab(fd, "\"", nb_tab);
    write_str(fd, data->data_name);
    write_str(fd, "\":");
}

void write_data(pars_data_t *data, int fd, int nb_tab)
{
    write_tab(fd, "{\n", nb_tab - 1);
    while (data) {
        writer_data_name(data, fd, nb_tab);
        writer_value(data, fd, nb_tab);
        data = data->next;
        if (data)
            write_str(fd, ",");
        write_str(fd, "\n");
    }
    write_tab(fd, "}", nb_tab - 1);
}

static void write_obj(pars_obj_t *obj, int fd)
{
    for (; obj; obj = obj->next) {
        write_data(obj->data, fd, 1);
        write_str(fd, "\n");
    }
}

int writer_json(char *filepath, pars_obj_t *obj, pars_data_t *data)
{
    int fd = open(filepath, O_CREAT | O_RDWR | O_TRUNC);

    if (fd == -1)
        return (CREATE_ERROR);
    if (obj == NULL)
        write_data(data, fd, 1);
    else
        write_obj(obj, fd);
    close(fd);
    return (0);
}
