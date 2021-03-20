/*
** EPITECH PROJECT, 2021
** stumper 2 : game of life
** File description:
** main
*/

#include "header.h"

int read_file(data d, char **av)
{
    struct stat *s = malloc(sizeof(struct stat));
    stat(av[1], s);
    int op = open(av[1], O_RDONLY);
    if (op == -1)
        exit(84);
    d->size_buffer = s->st_size;
    if (d->size_buffer == 0)
        exit(84);
    d->buf = malloc(sizeof(char) * (d->size_buffer + 1));
    ssize_t a = read(op, d->buf, d->size_buffer);
    d->map = my_str_to_wordarray(d->buf, '\n');
    d->save = my_str_to_wordarray(d->buf, '\n');
    if (my_getnbr(av[2]) < 0)
        exit(84);
    d->n = my_getnbr(av[2]);
    return (0);
}

void make_save(data d)
{
    for (int i = 0; d->map[i] != NULL; ++i)
        d->save[i] = my_strcpy(d->save[i], d->map[i]);
    return ;
}

void free_em_all(data d)
{
    free(d);
    return ;
}

int main(int ac, char **av)
{
    data d = malloc(sizeof(data));
    if (ac != 3)
        return (84);
    read_file(d, av);
    main_loop(d);
    free_em_all(d);
    return (0);
}