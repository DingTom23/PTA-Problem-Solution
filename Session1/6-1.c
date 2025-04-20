#include <stdio.h>

int Gcd(int x, int y);

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d\n", Gcd(a, b));
    return 0;
}

int Gcd(int x, int y){
    if (x == 0 && y == 0){
        return 1;
    }

    // 确保 x 是最大的
    // C语言特性，不写也无所谓
    // if (y > x){
    //     int temp;
    //     temp = y;
    //     y = x;
    //     x = temp;
    // }

    // 欧几里得算法原理
    // gcd(a,b)=gcd(b,a%b)
    while(y != 0){
        int temp = x % y;
        x = y;
        y = temp;
    }

    return x;
}