#include <stdio.h>

double price(double x);


int main()
{
    double buy,total;
    scanf("%lf",&buy); //输入上半年销售量
    total=price(buy);  //计算总提成
    printf("sum_s=%.2f\n",total);  
    scanf("%lf",&buy); //输入下半年销售量
    total=price(buy);  //计算总提成
    printf("sum_s=%.2f\n",total);
    return 0;
}

double price(double x) {
    static double total_sales = 0;
    double commission = 0;
    
    total_sales += x;
    
    if (total_sales < 5000) {
        commission = total_sales * 0.01;
    } else if (total_sales < 10000) {
        commission = total_sales * 0.05;
    } else {
        commission = total_sales * 0.10;
    }
    
    return commission;
}