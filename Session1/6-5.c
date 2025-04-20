#include <stdio.h>

int IsAutomorphic(int x);
void FindAutomorphic(int lower, int upper);

int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    FindAutomorphic(a, b);
    return 0;
}


int IsAutomorphic(int x) {
    if(x == 0) // 0 永远都是自守数
        return 1;
    
    int y = x * x;
    while(x > 0){ // 判断尾数是不是相等的
        if(y % 10 != x % 10)
            return 0;
        y /= 10;
        x /= 10;
    }
    return 1;
}

void FindAutomorphic(int lower, int upper){
    int check;
    for (int i = lower; i <= upper; i++){
        if(IsAutomorphic(i)){
            printf("%d\n", i);
            check = 1;
        }
    }
    if (!check){
        printf("None");
    }
}