/*
** EPITECH PROJECT, 2024
** my_compute_square_root
** File description:
** task05
*/

int my_compute_square_root(int nb)
{
    int i;

    for (i = 1; i <= nb; i++) {
        if (i * i == nb) {
            return i;
        }
    }
    return 0;
}
