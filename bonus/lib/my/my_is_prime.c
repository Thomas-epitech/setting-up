/*
** EPITECH PROJECT, 2024
** my_is_prime
** File description:
** task06
*/

int my_is_prime(int nb)
{
    if (nb == 2){
        return 1;
    }
    if (nb <= 0 || nb == 1 || nb % 2 == 0) {
        return 0;
    }
    for (int i = 3; i < nb; i += 2) {
        if (nb % i == 0) {
            return 0;
        }
    }
    return 1;
}
