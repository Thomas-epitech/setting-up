/*
** EPITECH PROJECT, 2024
** setting up
** File description:
** main
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include <stdio.h>

int main(int argc, char **argv)
{
    char **map;
    int line_nb = 0;
    int col_nb;

    if (arg_error_handler(argc, argv) == -1)
        return 84;
    if (argc == 2) {
        map = get_map_by_file(argv[1], &line_nb);
        col_nb = get_map_width(argv[1]) - 1;
    }
    if (argc == 3) {
        line_nb = my_getnbr(argv[1]);
        col_nb = my_getnbr(argv[1]);
        map = get_map_by_gen(line_nb, argv[2]);
        if (map == 0)
            return 84;
    }
    solve_map(map, line_nb, col_nb);
    free(map);
    return 0;
}
