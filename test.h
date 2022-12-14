#ifndef TEST_H
#define TEST_H

#include <stdio.h>
#include <unistd.h>


typedef struct
{
    int bread;
    char *str;
} r_value;

int ft_printf(const char *str, ...);

#endif // TEST_H