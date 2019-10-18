#include <stdio.h>
#include "debug.h"

int main(int argc,char* argv[])
{
    dbg_printf("Hello\n");
    dbg_printf("Hello %s\n","world");

    return 0;
}
