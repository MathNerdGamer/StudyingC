#include <stdio.h>
#include <stdlib.h>

long double pi();

int main(int argc, char **argv)
{
    printf("pi = %.11Lf\n", pi());
}

long double pi()
{
    long double pi_v = 3.0;
    int sign = 1;

    constexpr size_t ITERATIONS = 10000000UL;
    size_t n = 2;

    for( size_t i = 0; i < ITERATIONS; i++ )
    {
        // pi = 3 + 4*Sum[(-1)^(n+1)/(2n * (2n+1) * (2n+2)), n = 1 to infinity]
        pi_v += sign * (4.0L) / (n * (n + 1) * (n + 2));

        sign *= -1;

        n += 2;
    }

    return pi_v;
}
