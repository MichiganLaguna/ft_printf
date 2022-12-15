#include "test.h"

int main(void)
{
    r_value **buf;
    r_value **buf2;

    buf = single_capture(ft_printf, "ddddd", 5, 0, -2147483648, 2147483647, 2147483648);
    buf2 = single_capture(printf, "ddddd", 5, 0, -2147483648, 2147483647, 2147483648);
    printf("Flag D:\n");
    cmpfct(buf, buf2, "     ");
    free_rrvalue(buf);
    free_rrvalue(buf2);

    buf = single_capture(ft_printf, "cccc", 0, 32, -127, 'b');
    buf2 = single_capture(printf, "cccc", 0, 32, -127, 'b');
    printf("Flag C:\n");
    cmpfct(buf, buf2, "     ");
    free_rrvalue(buf);
    free_rrvalue(buf2);

    int c = 4;
    buf = single_capture(ft_printf, "ppppp", (void *)-1, &c, (int *)24, "hey");
    buf2 = single_capture(printf, "ppppp", (void *)-1, &c, (int *)24, "hey");
    printf("Flag P:\n");
    cmpfct(buf, buf2, "     ");
    free_rrvalue(buf);
    free_rrvalue(buf2);
}
