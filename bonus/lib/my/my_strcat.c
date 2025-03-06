/*
** EPITECH PROJECT, 2024
** my_strcat
** File description:
** task02
*/

#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int dest_len = my_strlen(dest);

    for (int i = 0; src[i] != '\0'; i++) {
        dest[dest_len + i] = src[i];
    }
    dest[dest_len + my_strlen(src) + 1] = '\0';
    return dest;
}
