/*
** EPITECH PROJECT, 2021
** JSON-Parser
** File description:
** parser
*/

#include "parser.h"

pars_data_t *json_obj(char **str)
{
    pars_data_t *data = malloc(sizeof(pars_data_t));
    pars_data_t *first_data = data;

    for (; **str; *str += (**str == ',')) {
        data->next = NULL;
        json_whitespace(str);
        if (**str == '}') {
            data->type = knull;
            break;
        }
        data->data_name = json_string(str);
        json_whitespace(str);
        *str += (**str == ':');
        json_value(str, data);
        if (**str == '}')
            break;
        data->next = malloc(sizeof(pars_data_t));
        data = data->next;
    }
    *str += (**str == '}');
    return (first_data);
}

pars_data_t *parser_json(char *filepath)
{
    char *str = NULL;
    char *copy;
    pars_data_t *data;

    if (read_file(filepath, &str))
        return NULL;
    copy = str;
    data = json_obj(&str);
    free(copy);
    return (data);
}
