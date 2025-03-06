/*
** EPITECH PROJECT, 2024
** my
** File description:
** task02
*/

#ifndef MY_H_
  #define MY_H_
int my_compute_power_rec(int, int);
int my_compute_square_root(int);
int my_find_prime_sup(int);
int my_getnbr(char const *);
int my_is_prime(int);
int my_isneg(int);
int my_put_nbr(int);
void my_putchar(char);
int my_putstr(char const *);
void my_putstrerr(char const *);
char *my_revstr(char *);
int my_showmem(char const *, int);
int my_showstr(char const *);
char *my_strcpy(char *, char const *);
void my_sort_int_array(int *, int);
char *my_strcapitalize(char *);
char *my_strcat(char *, char const *);
int my_strcmp(char const *, char const *);
int my_str_isalpha(char const *);
int my_str_islower(char const *);
int my_str_isnum(char const *);
int my_str_isprintable(char const *);
int my_str_isupper(char const *);
int my_strlen(char const *);
char *my_strlowcase(char *);
char *my_strncat(char *, char const *, int);
int my_strncmp(char const *, char const *, int);
char *my_strncpy(char *, char const *, int);
char *my_strstr(char *, char const *);
char *my_strupcase(char *);
void my_swap(int *, int *);
int arg_error_handler(int, char **);
char **get_map_by_file(char *, int *);
char **get_map_by_gen(int, char *);
void solve_map(char **, int, int);
int get_map_width(char *);
int get_len_first_line(char *);
int get_number_of_line(int, int);
int my_intlen(int);
int get_seed(char *);
#endif
