
int ft_printf(const char *str, ...);

#include <stdio.h>
#include "test.h"
#include <stdlib.h>


r_value single_capture_int(int (*f)(const char *str, ...), char *str, int arg)
{
    int pipes[2];
    int bread;
    int tmp_stdout;
    r_value    *out;

    fflush(stdout);
    dup(tmp_stdout, fileno(stdout)); // make a copy of stdout
    pipe(pipes); // create a pipe
    dup2(pipes[1], fileno(stdout)); // copy stdout to pipe and close stdout

    bread = f(str, arg);  // output to stdout is instead capture to pipe

    fflush(stdout); // clean 
    dup2(tmp_stdout, fileno(stdout));
    out = calloc(sizeof(r_value), bread + 1);
    read(pipes[0], out->str, bread);
    out->bread = bread;
    return (out);
}

int main(void)
{
    

}