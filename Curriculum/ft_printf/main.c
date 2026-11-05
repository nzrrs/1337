#include <stdio.h>

#define T(fmt, v) do { \
    printf("printf(%s, %s)\n", #fmt, #v); \
    printf("[" fmt "]\n\n", v); \
} while (0)

int main(void)
{
    T("%d", 42);
    T("%+d", 42);
    T("% d", 42);
    T("% +d", 42);
    T("%+ d", 42);
    T("%+d", -42);
    T("% d", -42);
    T("%+d", 0);
    T("% d", 0);
    T("%x", 255);
    T("%#x", 255);
    T("%#X", 255);
    T("%#x", 0);
    T("%# +%%x++#%d#####x", 255, 5);
    T("%+x", 255);
    T("% x", 255);
    T("%+u", 42);
    T("%#d", 42);
    T("%+s", "hi");
    T("%#c", 'a');
    return (0);
}
