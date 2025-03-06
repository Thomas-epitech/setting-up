/*
** EPITECH PROJECT, 2024
** setting up (bonus)
** File description:
** get_seed of random
*/

int get_seed(char *time)
{
    long int second = (time[0] - 48) * 100000 +
        (time[1] - 48) * 10000 +
        (time[3] - 48) * 1000 +
        (time[4] - 48) * 100 +
        (time[6] - 48) * 10 +
        (time[7] - 48);
    int final_nb;

    second += 5;
    second *= 77;
    final_nb = (second % 100);
    return final_nb;
}
