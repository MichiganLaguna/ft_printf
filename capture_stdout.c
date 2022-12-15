#include "test.h"

r_value *_capture(int (*f)(const char *str, ...), char *c, ...)
{
    int pipes[2];
    int bread;
    int tmp_stdout;
    r_value *out;
    va_list arg;

    fflush(stdout);
    tmp_stdout = dup(fileno(stdout)); // make a copy of stdout so we don't lose it
    pipe(pipes); // create a pipe
    dup2(pipes[1], fileno(stdout)); // copy stdout to pipe and close stdout

    va_start(arg, c);

    if (*c == 's')
        bread = f(c, va_arg(arg, char *));  // output to stdout is instead captured to pipe
    else if (*c == 'p' || *c == 'u' || *c == 'x' || *c == 'X' || *c == '%')
        bread = f(c, va_arg(arg, unsigned long));
    else if (*c == 'd' || *c == 'i')
        bread = f(c, va_arg(arg, int));

    va_end(arg);

    fflush(stdout); // clean 
    dup2(tmp_stdout, fileno(stdout)); // restore stdout
    out = malloc(sizeof(r_value));
    out->str = calloc(sizeof(char), bread + 1);
    read(pipes[0], out->str, bread); // read the exact string length
    out->bread = bread;
    return (out);
}

r_value *single_capture(int (*f)(const char *str, ...), char *str, ...)
{
    r_value    *out;
    int     i;
    va_list args;

    i = 0;
    va_start(args, str);
    while (str[i])
    {
        if (str[i] == 's')
            out = _capture(f, "s", va_arg(args, char *));
        else if (str[i] == 'p')
            out = _capture(f, "p", va_arg(args, void *));
        else if (str[i] == 'u')
            out = _capture(f, "u", va_arg(args, unsigned int));
        else if (str[i] == 'x')
            out = _capture(f, "x", va_arg(args, unsigned long));
        else if (str[i] == 'X')
            out = _capture(f, "X", va_arg(args, unsigned long));
        else if (str[i] == 'd')
            out = _capture(f, "d", va_arg(args, int));
        else if (str[i] == 'i')
            out = _capture(f, "i", va_arg(args, int));
        i++;
    }
    va_end(args);
    return (out);    
}

void    free_r_value(int nbr, ...)
{
    va_list args;
    r_value *tmp;

    va_start(args, nbr);
    while (nbr--)
    {
        tmp = va_arg(args, r_value*);
        free(tmp->str);
        free(tmp);
    }
    va_end(args);
}