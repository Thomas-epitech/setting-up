/*
** EPITECH PROJECT, 2024
** my_comput_power_rec
** File description:
** task04
*/

int my_compute_power_rec(int nb, int p)
{
    if (p == 0) {
        return 1;
    } else if (p < 0) {
        return 0;
    }
    return nb * my_compute_power_rec(nb, p - 1);
}
