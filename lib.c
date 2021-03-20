/*
** EPITECH PROJECT, 2021
** clean string
** File description:
** library
*/

#include "header.h"

int my_puts(str str, bool t)
{
    int i = 0;
    for (i; str[i] != '\0'; ++i);
        write(1, str, i);
    char c = '\n';
    if (t)
        write (1, &c, 1);
    return (0);
}

int my_putchar(char c)
{
    write(1, &c, 1);
    return (0);
}

int my_strlen(str str)
{
    int i = 0;
    for (i; str[i] != '\0'; ++i);
    return (i);
}

int my_putnbr(int n)
{
    if (n < 9)
        my_putchar(n + '0');
    else {
        my_putnbr(n / 10);
        my_putchar((n % 10) + '0');
    }
    return (0);
}

bool is_alpha(char c)
{
    switch (c) {
        case (' '): return (false);
        case ('\t'): return (false);
        case ('\n'): return (false);
        default: return (true);
    }
}
