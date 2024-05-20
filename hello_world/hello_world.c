#include <stdio.h>
#include <stdlib.h>

int main(int const argc, [[maybe_unused]] char const **argv)
{
    printf("Hello, world!\n");

    for( int i = 1; i < argc; i++ )
    {
        printf("Hello, %s!\n", argv[i]);
    }

    return EXIT_SUCCESS;
}
