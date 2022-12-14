#include "test.h"

r_value *single_capture_int(int (*f)(const char *str, ...), char *str, int arg)
{
    int pipes[2];
    int bread;
    int tmp_stdout;
    r_value    *out;

    fflush(stdout);
    tmp_stdout = dup(fileno(stdout)); // make a copy of stdout so we don't lose it
    pipe(pipes); // create a pipe
    dup2(pipes[1], fileno(stdout)); // copy stdout to pipe and close stdout

    bread = f(str, arg);  // output to stdout is instead captured to pipe

    fflush(stdout); // clean 
    dup2(tmp_stdout, fileno(stdout)); // restore stdout
    out = malloc(sizeof(r_value));
    out->str = calloc(sizeof(char), bread + 1);
    read(pipes[0], out->str, bread); // read the exact string length
    out->bread = bread;
    return (out);
}

r_value *single_capture_uint(int (*f)(const char *str, ...), char *str, size_t arg)
{
    int pipes[2];
    int bread;
    int tmp_stdout;
    r_value    *out;

    fflush(stdout);
    tmp_stdout = dup(fileno(stdout)); // make a copy of stdout so we don't lose it
    pipe(pipes); // create a pipe
    dup2(pipes[1], fileno(stdout)); // copy stdout to pipe and close stdout

    bread = f(str, arg);  // output to stdout is instead captured to pipe

    fflush(stdout); // clean 
    dup2(tmp_stdout, fileno(stdout)); // restore stdout
    out = malloc(sizeof(r_value));
    out->str = calloc(sizeof(char), bread + 1);
    read(pipes[0], out->str, bread); // read the exact string length
    out->bread = bread;
    return (out);
}

r_value *single_capture_str(int (*f)(const char *str, ...), char *str, char *arg)
{
    int pipes[2];
    int bread;
    int tmp_stdout;
    r_value    *out;

    fflush(stdout);
    tmp_stdout = dup(fileno(stdout)); // make a copy of stdout so we don't lose it
    pipe(pipes); // create a pipe
    dup2(pipes[1], fileno(stdout)); // copy stdout to pipe and close stdout

    bread = f(str, arg);  // output to stdout is instead captured to pipe

    fflush(stdout); // clean 
    dup2(tmp_stdout, fileno(stdout)); // restore stdout
    out = malloc(sizeof(r_value));
    out->str = calloc(sizeof(char), bread + 1);
    read(pipes[0], out->str, bread); // read the exact string length
    out->bread = bread;
    return (out);
}

void    free_r_value()