#include "test.h"

// DON'T USE THIS
// take as args a printf-like function, a flag and one argument
// ... are used because type can variate.
// the type recognised are those represented by the following flags in printf:
// cpsiudxX%
r_value *_capture(int (*f)(const char *str, ...), char c, ...)
{
    int pipes[2];
    int bread;
    int tmp_stdout;
    char    str[3];
    r_value *out;
    va_list arg;

    fflush(stdout);
    tmp_stdout = dup(fileno(stdout)); // make a copy of stdout so we don't lose it
    pipe(pipes); // create a pipe
    dup2(pipes[1], fileno(stdout)); // copy stdout to pipe and close stdout

    va_start(arg, c);
    str[0] = '%';
    str[1] = c;
    str[2] = 0;
    if (c == 's')
        bread = f(str, va_arg(arg, char *));  // output to stdout is instead captured to pipe
    else if (c == 'p' || c == 'u' || c == 'x' || c == 'X' || c == '%')
        bread = f(str, va_arg(arg, unsigned long));
    else if (c == 'd' || c == 'i' || c == 'c')
        bread = f(str, va_arg(arg, int));

    va_end(arg);

    fflush(stdout); // clean 
    dup2(tmp_stdout, fileno(stdout)); // restore stdout
    out = malloc(sizeof(r_value));
    out->str = calloc(sizeof(char), bread + 1);
    read(pipes[0], out->str, bread); // read the exact string length
    out->bread = bread;
    return (out);
}

// Return a null terminated list of r_value *.
// Take a printf like function, a string containing flags separated by nothing
// and as mush arguments as there is flags.
// The flags are the following cpsiudxX% and means the same as in printf
r_value **single_capture(int (*f)(const char *str, ...), char *str, ...)
{
    r_value    **out;
    int     i;
    int     len;
    va_list args;

    len = 0;
    while (str[len])
        len++;
    out = malloc(sizeof(r_value *) * (len + 1));
    i = 0;
    va_start(args, str);
    while (str[i])
    {
        if (str[i] == 's')
            out[i] = _capture(f, str[i], va_arg(args, char *));
        else if (str[i] == 'u' || str[i] == 'x' || str[i] == 'X' || str[i] == 'p')
            out[i] = _capture(f, str[i], va_arg(args, unsigned int));
        else if (str[i] == 'd' || str[i] == 'i' || str[i] == 'c')
            out[i] = _capture(f, str[i], va_arg(args, int));
        else if (str[i] == '%')
            out[i] = _capture(f, str[i]);
        i++;
    }
    va_end(args);
    out[i] = (r_value *)0;
    return (out);    
}

// free nbr numbers of r_value,
// make sure you enter exactly nbr numbers of r_value
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

// free an array of r_value*
void    free_rrvalue(r_value **out)
{
    int i;

    i = 0;
    if (out)
    {
        while (out[i])
        {
            free_r_value(1, out[i]);
            i++;
        }
        free(out);
    }
}

// compare two r_value** buf and buf2 with the first one being from printf
void    cmpfct(r_value **buf, r_value **buf2, char *padding)
{
    int i;

    i = 0;
    while (buf[i] && buf2[i])
    {
        if (buf[i]->bread == buf2[i]->bread && !strcmp(buf[i]->str, buf2[i]->str))
            printf("%s%d:OK\n", padding, i + 1);
        else
            printf("%s%d:KO\n%sprintf: [%s][%d]\n%sft_printf: [%s][%d]\n", padding, i + 1, padding, buf[i]->str, buf[i]->bread, padding, buf2[i]->str, buf2[i]->bread);
        i++;
    }
}