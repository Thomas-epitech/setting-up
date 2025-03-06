/*
** EPITECH PROJECT, 2024
** my_find_prime_sup
** File description:
** task07
*/

#include "my.h"

int my_find_prime_sup(int nb)
{
    int i;

    if (my_is_prime(nb)) {
        return nb;
    }
    for (i = nb + 1; i <= 2147483647; i++) {
        if (my_is_prime(i)) {
            return i;
        }
    }
    return 0;
}
