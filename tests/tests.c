/*
** EPITECH PROJECT, 2022
** JSON-Parser
** File description:
** TODO: add description
*/
#include "../inc/parser.h"

int main()
{
    pars_data_t *data = parser_json("test.json");

    printf("%s", data->data_name);
}
