/**
 * newton-raphson-sqrt.c
 * @author Wang Guibao (https://github.com/wangguibao)
 * @brief  Newton-Raphson method for calculating square root.
 */
#include <stdio.h>

double newton_raphson_sqrt(unsigned int n)
{
    double result = n;

    double epsilon = 1e-6;

    while (result * result - n > epsilon) {
        result = (result + n / result) / 2;
        printf("%lf\n", result);
    }

    return result;
}

int main()
{
    int n = 0;
    int ret = 0;

    printf("Calculate square root for number: ");
    ret = scanf("%u", &n);
    if (ret != 1) {
        return -1;
    }

    printf("sqrt(%u) = %10f\n", n, newton_raphson_sqrt(n));

    return 0;
}
