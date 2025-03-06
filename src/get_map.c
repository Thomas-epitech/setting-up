/*
** EPITECH PROJECT, 2024
** setting up
** File description:
** functions to get the map in a char **
*/
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "my.h"



static void get_len_line(char *buffer, int buffer_size, int *count,
    int *line_break_flag)
{
    for (int i = 0; i < buffer_size; i++) {
        if (buffer[i] == '\n') {
            *line_break_flag = 1;
            *count += 1;
            break;
        }
        (*count)++;
    }
}

int get_len_first_line(char *pathname)
{
    int fd = open(pathname, O_RDONLY);
    int count = 0;
    int buffer_size = 10;
    char buffer[buffer_size];
    int line_break_flag = 0;
    int read_value = read(fd, buffer, 10);

    while (read_value != 0 && !line_break_flag) {
        get_len_line(buffer, buffer_size, &count, &line_break_flag);
        read_value = read(fd, buffer, 10);
    }
    close(fd);
    return count;
}

int get_number_of_line(int fd, int len_first_line)
{
    char buffer[len_first_line + 1];

    read(fd, buffer, len_first_line);
    buffer[len_first_line] = '\0';
    return my_getnbr(buffer);
}

int get_map_width(char *pathname)
{
    int fd = open(pathname, O_RDONLY);
    int count = 0;
    int buffer_size = 500;
    char buffer[buffer_size];
    int line_break_flag = 0;
    int read_value;

    read(fd, buffer, get_len_first_line(pathname));
    read_value = read(fd, buffer, buffer_size);
    while (read_value != 0 && !line_break_flag) {
        get_len_line(buffer, buffer_size, &count, &line_break_flag);
        read_value = read(fd, buffer, buffer_size);
    }
    close(fd);
    return count;
}

char **get_map_by_file(char *pathname, int *line_nb)
{
    int fd = open(pathname, O_RDONLY);
    char **map;
    int map_width = get_map_width(pathname) - 1;
    char discard_buffer[1];

    *line_nb = get_number_of_line(fd, get_len_first_line(pathname));
    map = malloc(sizeof(char *) * *line_nb);
    if (*line_nb == 0 || map == NULL) {
        free(map);
        return 0;
    }
    for (int i = 0; i < *line_nb; i++) {
        map[i] = malloc(sizeof(char) * map_width);
        read(fd, map[i], map_width);
        read(fd, discard_buffer, 1);
    }
    close(fd);
    return map;
}

char **get_map_by_gen(int size, char *pattern)
{
    char **map = malloc(sizeof(char *) * size);
    int pattern_length = my_strlen(pattern);
    int pattern_index = 0;

    if (pattern[0] == '\0')
        return 0;
    for (int i = 0; i < size; i++) {
        map[i] = malloc(sizeof(char) * size + 1);
        for (int j = 0; j < size; j++) {
            map[i][j] = pattern[pattern_index % pattern_length];
            pattern_index++;
        }
        map[i][size] = '\0';
    }
    return map;
}
