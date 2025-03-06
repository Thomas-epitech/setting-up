/*
** EPITECH PROJECT, 2024
** my_strlen
** File description:
** strlen
*/
#include "stdio.h"
int my_intlen(int n)
{
    int len = 0;

    if (n == 0) {
        return 1;
    }
    if (n < 0) {
        len++;
        n *= -1;
    }
    while (n > 9) {
        n = n / 10;
        len++;
    }
    return len + 1;
}
