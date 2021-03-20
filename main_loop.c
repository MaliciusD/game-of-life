/*
** EPITECH PROJECT, 2021
** stumper 2 : game of life
** File description:
** main loop
*/

#include "header.h"

bool check_empty_cell(data d, int i, int k)
{
    str *t = d->save;
    int nei = 0;
    bool q[] = {
        (t[i][k + 1] != '\0' && t[i][k + 1] == 'X'),
        (i - 1 >= 0 && t[i][k + 1] != '\0' && t[i - 1][k + 1] == 'X'),
        (i - 1 >= 0 && t[i - 1][k] == 'X'),
        (i - 1 >= 0 && k - 1 >= 0 && t[i - 1][k - 1] == 'X'),
        (k - 1 >= 0 && t[i][k - 1] == 'X'),
        (k - 1 >= 0 && t[i + 1] != NULL && t[i + 1][k - 1] == 'X'),
        (t[i + 1] != NULL && t[i + 1][k] == 'X'),
        (t[i + 1] != NULL && t[i][k + 1] != '\0' && t[i + 1][k + 1] == 'X'),
    };
    for (int l = 0; l < 8; ++l)
        nei += (q[l]) ? 1 : 0;
    if (nei == 3 || nei == 4) {
        d->map[i][k] = 'X';
        return (true);
    } return (false);
}

bool check_l_cells(data d, int i, int k)
{
    str *t = d->save;
    int nei = 0;
    bool q[] = {
        (t[i][k + 1] != '\0' && t[i][k + 1] == 'X'),
        (i - 1 >= 0 && t[i][k + 1] != '\0' && t[i - 1][k + 1] == 'X'),
        (i - 1 >= 0 && t[i - 1][k] == 'X'),
        (i - 1 >= 0 && k - 1 >= 0 && t[i - 1][k - 1] == 'X'),
        (k - 1 >= 0 && t[i][k - 1] == 'X'),
        (k - 1 >= 0 && t[i + 1] != NULL && t[i + 1][k - 1] == 'X'),
        (t[i + 1] != NULL && t[i + 1][k] == 'X'),
        (t[i + 1] != NULL && t[i][k + 1] != '\0' && t[i + 1][k + 1] == 'X'),
    };
    for (int l = 0; l < 8; ++l)
        nei += (q[l]) ? 1 : 0;
    if (betw(-1, nei, 2) || betw(3, nei, 9)) {
        d->map[i][k] = '.';
        return (true);
    } return (false);
}

void make_operations(data d)
{
    bool a;
    for (int i = 0; d->save[i] != NULL; ++i)
        for (int k = 0; d->save[i][k] != '\0'; ++k)
            switch (d->save[i][k]) {
            case ('X'):
                a = check_l_cells(d, i, k);
                break;
            case ('.'):
                a = check_empty_cell(d, i, k);
                break;
            default:
                my_puterror("Invalid character\n");
                exit(84);
            }
    return ;
}

void display(data d)
{
    for (int i = 0; d->map[i] != NULL; ++i)
        my_puts(d->map[i], true);
    return ;
}

void main_loop(data d)
{
    for (int i = 0; i < d->n; ++i) {
        make_operations(d);
        make_save(d);
    }
    display(d);
    return ;
}