#include <stdio.h>

int reverse( int number );
    
int main()
{
    int n;

    scanf("%d", &n);
    printf("%d\n", reverse(n));

    return 0;
}

int reverse(int number) {
    int reversed = 0;  // 用来记录最终反转后的数字
    int sign = 1;      // 用来记录正负号
    
    // 如果 number 是负数，记录符号，并把 number 转成正数
    if (number < 0) {
        sign = -1;
        number = -number;
    }
    
    // 当 number 不为 0 时，不断“取出”它的最后一位并“拼接”到 reversed 上
    while (number != 0) {
        // 先让 reversed 原来的内容整体向左移动一位（*10），
        // 然后加上当前 number 的最后一位数字 (number % 10)
        reversed = reversed * 10 + number % 10;
        
        // 将 number 去掉最后一位，继续处理
        number /= 10;
    }
    
    // 如果最初的数是负的，就把结果变为负数
    return sign * reversed;
}