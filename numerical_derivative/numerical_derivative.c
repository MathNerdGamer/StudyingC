#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long double func1(long double);
long double func2(long double);
long double differentiate(long double, long double (*f)(long double));

int main([[maybe_unused]] int argc, [[maybe_unused]] char **argv)
{
    constexpr long double pi = 3.14159265359L;

    printf("The derivative of x^2 + e^x at x = 0: %.10Lf\n\n",
           differentiate(0, func1));

    printf("The derivative of x^2 * e^x at x = 1: %.10Lf\n\n",
           differentiate(1, func2));

    printf("The derivative of sin(x) at x = pi/4: %.10Lf\n\n",
           differentiate(pi / 4.0L, sinl));

    printf("The derivative of tan(x) at x = pi/6: %.10Lf\n\n",
           differentiate(pi / 6.0L, tanl));

    printf("The derivative of cosh(x) at x = 3: %.10Lf\n\n",
           differentiate(3, coshl));
}

long double func1(long double x)
{
    return x * x + expl(x);
}

long double func2(long double x)
{
    return x * x * expl(x);
}

long double differentiate(long double x, long double (*f)(long double))
{
    constexpr long double h = 0.000001L;

    // f'(x) =
    // (-f(x + 2 * h) + 8 * f(x + h) - 8 * f(x - h) + f(x - 2 * h)) /
    // (12 * h)
    //                  + O(h^4)
    return (-f(x + 2 * h) + 8 * f(x + h) - 8 * f(x - h) + f(x - 2 * h)) /
           (12 * h);
}