/*
** EPITECH PROJECT, 2024
** my_str_isprintable
** File description:
** task16
*/
#include <stdio.h>
int my_str_isprintable(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] >= 0 && str[i] <= 31)
            return 0;
    return 1;
}
