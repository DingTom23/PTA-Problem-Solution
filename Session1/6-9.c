#include <stdio.h>

double P( int n, double x );

int main()
{
    int n;
    double x;
    
    scanf("%d %lf", &n, &x);
    printf("%.2f\n", P(n,x));
    
    return 0;
}

double P(int n, double x) {
    if (n == 0) {
        return 1.0;
    } else if (n == 1) {
        return x;
    } else if (n > 1){
        double temp1 = (2.0 * n - 1.0) * P(n - 1, x);
        double temp2 = (n - 1.0) * P(n - 2, x);
        return (temp1 - temp2) / n;
    }
}