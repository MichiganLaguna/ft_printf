#ifndef TEST_H
#define TEST_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <string.h>


typedef struct r_value_s
{
    int bread;
    char *str;
} r_value;

int ft_printf(const char *str, ...);
r_value **single_capture(int (*f)(const char *str, ...), char *str, ...);
void    free_r_value(int nbr, ...);
void    free_rrvalue(r_value **out);
r_value *_capture(int (*f)(const char *str, ...), char c, ...);
void    cmpfct(r_value **buf, r_value **buf2, char *padding);

#endif // TEST_H