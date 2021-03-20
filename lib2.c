/*
** EPITECH PROJECT, 2021
** lib
** File description:
** stumper
*/

#include "header.h"

void my_puterror(char *str)
{
    write(2, str, my_strlen(str));
}

char *my_strcpy(char *dest, char *src)
{
    int x = 0;

    for (int i = 0; src[i] != '\0'; ++i, ++x) {
        dest[x] = src[i];
    } dest[x] = '\0';
    return (dest);
}

char **my_str_to_wordarray(char *src, char c)
{
    int x = 0;
    int y = 0;

    char **str = malloc(sizeof(char *) * (my_strlen(src) + 1));
    for (int i = 0; i != my_strlen(src); i++)
        str[i] = malloc(sizeof(char) * (my_strlen(src)));

    for (int i = 0; src[i] != '\0'; i++) {
        if (src[i] != c) {
            str[x][y] = src[i];
            y++;
        } if (src[i] == c && src[i + 1] != c) {
            x++;
            y = 0;
        }
    } str[x][y] = '\0';
    str[x + 1] = NULL;

    return (str);
}

bool my_strcmp(char *str, char *str2)
{
    int x = 0;
    if (my_strlen(str) != my_strlen(str2))
        return (false);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == str2[i])
            x++;
    }
    if (x != my_strlen(str))
        return (false);
    return (true);
}

int my_getnbr(char *src)
{
    int res = 0;

    for (int i = 0; src[i] != '\0'; i++) {
        if (src[i] == '-')
            return (-1);
        else if (src[i] >= '0' && src[i] <= '9')
            res = res * 10 + src[i] - '0';
    }
    return (res);
}