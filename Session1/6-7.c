#include <stdio.h>

double calc_pow( double x, int n );

int main()
{
    double x;
    int n;

    scanf("%lf %d", &x, &n);
    printf("%.0f\n", calc_pow(x, n));

    return 0;
}

double calc_pow( double x, int n ){
    int result = 1;
    while(n > 0){
        result *= x;
        n--;
    }
    return result;
}