#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void test(char *str)
{
    if (str[-1])
        printf("err\n");
}

int main()
{
    char *str;

    str = strdup("test");
    test(str);

}