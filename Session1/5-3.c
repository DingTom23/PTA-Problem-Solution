#include <stdio.h>
#define M 3
#define N 4

void small(int a[][N],int b[]);

int main()
{
    int i,j,x[M][N],y[N];
    for(i=0;i<M;i++)
        for(j=0;j<N;j++)
            scanf("%d",&x[i][j]);
    small(x,y);
    for(i=0;i<N;i++)
        printf("%d ",y[i]);
    return 0;
}

void small(int a[][N], int b[]) {
    int i, j;
    for (j = 0; j < N; j++) {
        b[j] = a[0][j];
        for (i = 0; i < M; i++) {
            if (a[i][j] < b[j]) {
                b[j] = a[i][j];
            }
        }
    }
}