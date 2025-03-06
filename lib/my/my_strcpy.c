/*
** EPITECH PROJECT, 2024
** my_strcpy
** File description:
** task01
*/

#include "my.h"

char *my_strcpy(char *dest, char const *src)
{
    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    dest[my_strlen(src)] = '\0';
    return dest;
}
