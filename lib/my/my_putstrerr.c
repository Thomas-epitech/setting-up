/*
** EPITECH PROJECT, 2024
** lib of setting up
** File description:
** my_pustrerr function
*/

#include <unistd.h>

void my_putstrerr(char const *str)
{
    while (*str != '\0') {
        write(2, str, 1);
        str++;
    }
}
