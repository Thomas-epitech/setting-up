/*
** EPITECH PROJECT, 2024
** setting up
** File description:
** solver
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "max.h"
#include "my.h"
#include "colors.h"

static int get_min(int a, int b, int c)
{
    if (a < b)
        return a < c ? a : c;
    else
        return b < c ? b : c;
}

static int get_value_for_net(char **map, int **net, int j, int i)
{
    if (map[i][j] == 'o')
        return 0;
    return (get_min(net[i - 1][j], net[i][j - 1], net[i - 1][j - 1]) + 1);
}

static void update_max_value(max_t *max_value, int value, int j, int i)
{
    if (max_value->value > value)
        return;
    if (max_value->value < value) {
        max_value->value = value;
        max_value->j = j;
        max_value->i = i;
    }
    if (max_value->value == value) {
        if (i < max_value->i) {
            max_value->i = i;
            max_value->j = j;
        }
        if (i == max_value->i) {
            max_value->i = max_value->j > j ? i : max_value->i;
            max_value->j = max_value->j > j ? j : max_value->j;
        }
    }
}

static int **fill_net(char **map, max_t *max_value, int nb_line, int nb_col)
{
    int **net = malloc(sizeof(int *) * nb_line);

    for (int i = 0; i < nb_line; i++) {
        net[i] = malloc(sizeof(int) * nb_col);
        net[i][0] = map[i][0] == '.' ? 1 : 0;
        update_max_value(max_value, net[i][0], 0, i);
    }
    for (int i = 0; i < nb_col; i++) {
        net[0][i] = map[0][i] == '.' ? 1 : 0;
        update_max_value(max_value, net[0][i], i, 0);
    }
    for (int j = 1; j < nb_col; j++) {
        for (int i = 1; i < nb_line; i++) {
            net[i][j] = get_value_for_net(map, net, j, i);
            update_max_value(max_value, net[i][j], j, i);
        }
    }
    return net;
}

char **get_result(char **map, max_t *max, int nb_line, int nb_col)
{
    char **result = malloc(sizeof(char *) * nb_line);

    for (int i = 0; i < nb_line; i++) {
        result[i] = malloc(sizeof(char) * nb_col);
        for (int j = 0; j < nb_col; j++) {
            result[i][j] = i <= max->i && i > max->i - max->value &&
                j <= max->j && j > max->j - max->value ? 'x' : map[i][j];
        }
    }
    return result;
}

static int cross_in_line(char *line)
{
    for (int i = 0; line[i] != '\0'; i++)
        if (line[i] == 'x')
            return i;
    return -1;
}

static void print_with_colors(char **map, int nb_line, int nb_col,
    int max_value)
{
    int cross_index;

    for (int i = 0; i < nb_line; i++) {
        cross_index = cross_in_line(map[i]);
        if (cross_index == -1)
            write(1, map[i], nb_col);
        else {
            write(1, map[i], cross_index);
            write(1, COLOR_RED, my_strlen(COLOR_RED));
            write(1, COLOR_BOLD, my_strlen(COLOR_BOLD));
            write(1, map[i] + cross_index, max_value);
            write(1, COLOR_RESET, my_strlen(COLOR_RESET));
            write(1, map[i] + cross_index + max_value, nb_col -
                (cross_index + max_value));
        }
        my_putchar('\n');
    }
}

void solve_map(char **map, int nb_line, int nb_col)
{
    max_t max_value = {0, 0, 0};
    int **net = fill_net(map, &max_value, nb_line, nb_col);
    char **result = get_result(map, &max_value, nb_line, nb_col);

    print_with_colors(result, nb_line, nb_col, max_value.value);
    free(result);
    free(net);
}
