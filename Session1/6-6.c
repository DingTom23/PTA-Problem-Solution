#include <stdio.h>

int fn( int a, int n );
int SumA( int a, int n );
    
int main()
{
    int a, n;

    scanf("%d %d", &a, &n);
    printf("fn(%d, %d) = %d\n", a, n, fn(a,n));        
    printf("s = %d\n", SumA(a,n));    
    
    return 0;
}

int fn( int a, int n ){
    if (a == 0 || n == 0){
        return 0;
    }
    int result = 0;
    while(n > 0){
        result *= 10;
        result += a;
        n--;
    }
    return result;
}

int SumA( int a, int n ){
    int result = 0;
    int ios = fn(a, n);
    while (ios > 0){
        result += ios;
        ios /= 10;
    }
    return result;
}