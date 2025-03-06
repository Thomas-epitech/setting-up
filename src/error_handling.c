/*
** EPITECH PROJECT, 2024
** setting up
** File description:
** error handling functions
*/

#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include "my.h"

static int reopen_file(int fd, char *filename)
{
    close(fd);
    return open(filename, O_RDONLY);
}

static int check_number_of_arguments(int argc)
{
    if (argc != 2 && argc != 3) {
        my_putstrerr("Invalid number of arguments\n");
        return -1;
    }
    return 0;
}

static int handle_file_arg(char *file)
{
    int fd = open(file, O_RDONLY);

    if (fd == -1) {
        my_putstrerr(file);
        my_putstrerr(": No such file or directory\n");
        return -1;
    }
    close(fd);
    return 0;
}

static int check_file_characters(char *buffer, int map_width)
{
    for (int i = 0; i < map_width - 1; i++)
        if (buffer[i] != '.' && buffer[i] != 'o')
            return -1;
    if (buffer[map_width - 1] != '\n')
        return -1;
    return 0;
}

static int check_file_content(int fd, int map_width, int line_nb)
{
    char buffer[map_width];
    int read_value = read(fd, buffer, map_width);
    int lines_read = 0;

    while (read_value != 0) {
        lines_read++;
        if (check_file_characters(buffer, map_width))
            return -1;
        read_value = read(fd, buffer, map_width);
    }
    if (lines_read != line_nb)
        return -1;
    return 0;
}

static int check_file_validity(char *file)
{
    int fd = open(file, O_RDONLY);
    int buffer_size = 500;
    char buffer[buffer_size];
    int line_nb;
    int map_width;

    if (read(fd, buffer, buffer_size) == 0)
        return -1;
    fd = reopen_file(fd, file);
    line_nb = get_number_of_line(fd, get_len_first_line(file));
    if (line_nb == 0 && buffer[0] != '0')
        return -1;
    map_width = get_map_width(file);
    if (check_file_content(fd, map_width, line_nb) == -1)
        return -1;
    return 0;
}

static int handle_gen_first_arg(char *arg)
{
    for (int i = 0; i < my_strlen(arg); i++) {
        if (arg[i] < '0' || arg[i] > '9') {
            my_putstrerr(arg);
            my_putstrerr(": Invalid argument\n");
            return -1;
        }
    }
    if (my_getnbr(arg) > 11000) {
        my_putstrerr(arg);
        my_putstrerr(": Size must be below 11000\n");
        return -1;
    }
    return 0;
}

static int handle_gen_second_arg(char *arg)
{
    for (int i = 0; i < my_strlen(arg); i++) {
        if (arg[i] != '.' && arg[i] != 'o') {
            my_putstrerr(arg);
            my_putstrerr(": Invalid argument\n");
            return -1;
        }
    }
    return 0;
}

int arg_error_handler(int argc, char **argv)
{
    int err_flag = 0;

    if (check_number_of_arguments(argc) == -1)
        return -1;
    if (argc == 2) {
        if (handle_file_arg(argv[1]) == -1)
            return -1;
        if (check_file_validity(argv[1]) == -1) {
            my_putstrerr("Invalid file\n");
            return -1;
        }
    } else {
        err_flag += handle_gen_first_arg(argv[1]);
        err_flag += handle_gen_second_arg(argv[2]);
    }
    return err_flag ? -1 : 0;
}
