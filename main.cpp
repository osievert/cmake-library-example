#include <stdio.h>

#include "dynamic.h"

int main(int argc, char* argv[])
{
    printf("hello, %d\n", dynamicfn(42));
    return 0;
}

