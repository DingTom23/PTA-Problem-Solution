#include <stdio.h>

double fact( int n );
double factsum( int n );

int main()
{
    int n;

    scanf("%d",&n);
    printf("fact(%d) = %.0f\n", n, fact(n));
    printf("sum = %.0f\n", factsum(n));
        
    return 0;
}

double fact( int n ){
    double temp = 1;
    for (int i = 1; i <= n; i++){
        temp *= i;
    }
    return temp;
}

double factsum( int n ){
    int sum = 0;
    for (int i = n; i > 0; i--){
        sum += fact(i);
    }
    return sum;
}