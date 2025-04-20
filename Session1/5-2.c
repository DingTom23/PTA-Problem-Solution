#include <stdio.h>
#define N 50
int ReadData(int a[]);
void DataSort(int a[], int n);
void PrintData(int a[], int n);
int main()
{
    int a[N], n;
    n = ReadData(a);
    printf("n=%d\n", n);
    if(n)
    { DataSort(a, n);
      printf("After sort: ");
      PrintData(a, n);
    }
    return 0;
}

int ReadData(int a[])
{
    int i = -1;
    do{
        i++;
        scanf("%d", &a[i]);
    }while (a[i] >= 0);
    return i;
}

void DataSort(int a[], int n) {
    int i, j;
    int sortRoundtime = 0;
    int swapped;

    // 外层最多 n-1 趟
    for (i = 0; i < n - 1; i++) {
        swapped = 0; // 每趟开始前先将 swapped 置为 0

        // 内层比较范围：从 0 到 n - i - 2
        // 因为每趟之后，末尾已经排好 i 个元素
        for (j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                // 交换
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                swapped = 1;
            }
        }

       
        if (swapped == 0) {
            break;
        }

        sortRoundtime++;
        printf("第%d趟：", sortRoundtime);
        for (int k = 0; k < n; k++) {
            printf("%d", a[k]);
            if (k < n - 1) printf(" ");
        }
        printf("\n");
    }
}

void PrintData(int a[], int n)
{
    int i;
    for (i=0; i<n; i++)
    {  if (i!=0)  printf(" ");
       printf("%d", a[i]);
    }
    printf("\n");
}
