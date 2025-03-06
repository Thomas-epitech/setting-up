/*
** EPITECH PROJECT, 2024
** my_revstr
** File description:
** task03
*/

#include "my.h"

void my_swap_char(char *a, char *b)
{
    char temp = *a;

    *a = *b;
    *b = temp;
}

char *my_revstr(char *str)
{
    int str_len = my_strlen(str);
    int i;
    char *start;
    char *end;

    for (i = 0; i < str_len / 2; i++) {
        str += i;
        start = str;
        str -= i;
        str += (str_len - i - 1);
        end = str;
        my_swap_char(start, end);
        str -= (str_len - i - 1);
    }
    return str;
}
