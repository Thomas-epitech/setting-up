/*
** EPITECH PROJECT, 2024
** my_sort_int_array
** File description:
** task06
*/

#include <stdio.h>

void exchange(int i, int j, int *tab)
{
    int tmp;

    if (tab[i] > tab[j]) {
        tmp = tab[i];
        tab[i] = tab[j];
        tab[j] = tmp;
    }
}

void my_sort_int_array(int *tab, int size)
{
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            exchange(i, j, tab);
        }
    }
}
