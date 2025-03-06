/*
** EPITECH PROJECT, 2024
** my_strstr
** File description:
** task05
*/

#include "my.h"
#include <stdio.h>

char *my_strstr(char *str, char const *to_find)
{
    int i;
    int len_to_find = my_strlen(to_find);
    int len_str = my_strlen(str);

    for (i = 0; i < len_str - len_to_find; i++) {
        if (my_strncmp(str, to_find, len_to_find) == 0) {
            return str;
        }
        str++;
    }
    return NULL;
}
