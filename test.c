/*
** EPITECH PROJECT, 2022
** JSON-Parser
** File description:
** TODO: add description
*/
#include <stdio.h>

int main()
{
    FILE *a = fopen("./Makefile", "r");
    char *str = NULL;
    char *str2 = NULL;
    char buff[4096] = {};

    while (fscanf(a, "%m[^\n]\n", &str) != EOF) {
        if (str)
            printf("%s|", str);
    }
}
