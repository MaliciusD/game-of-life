/*
** EPITECH PROJECT, 2021
** stumper 2 : game of life
** File description:
** header
*/

#ifndef HEAD
#define HEAD

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

typedef char * str;
typedef enum {
    false,
    true
} bool;

typedef struct {
    str buf;
    str *map;
    str *save;
    int n;
    int size_buffer;
} *data;

#define betw(a, b, c) (a < b && b < c) ? true : false

//  lib
int my_puts(str str, bool t);
int my_putchar(char c);
int my_strlen(str str);
int my_putnbr(int n);
bool is_alpha(char c);
void my_puterror(char *str);
char *my_strcpy(char *dest, char *src);
char **my_str_to_wordarray(char *src, char c);
bool my_strcmp(char *str, char *str2);
int my_getnbr(char *src);

//  main loop
void make_save(data d);
void main_loop(data d);
void make_operations(data d);
void display(data d);

//  check my cells boi
bool check_empty_cell(data d, int i, int k);
bool check_l_cells(data d, int i, int k);

#endif/* !HEAD */