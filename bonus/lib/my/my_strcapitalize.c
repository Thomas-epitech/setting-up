/*
** EPITECH PROJECT, 2024
** my_strcapitalize
** File description:
** task10
*/

int in_alphabet(char str)
{
    return (str >= 'a' && str <= 'z') || (str >= 'A' && str <= 'Z');
}

int is_first_letter(char *str, char c)
{
    char pre;

    if (c == 0)
        return 1;
    pre = str[c - 1];
    if (in_alphabet(pre) || (pre >= '0' && pre <= '9')) {
        return 0;
    }
    return 1;
}

void switch_case(char *str, int c)
{
    if (str[c] >= 'a' && str[c] <= 'z') {
        str[c] -= 32;
    } else if (str[c] >= 'A' && str[c] <= 'Z') {
        str[c] += 32;
    }
}

char *my_strcapitalize(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z' && is_first_letter(str, i))
            switch_case(str, i);
        if (!(is_first_letter(str, i)) && str[i] >= 'A' && str[i] <= 'Z')
            switch_case(str, i);
    }
    return str;
}
