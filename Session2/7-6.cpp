/*
设计一个矩阵类Matrix（整型动态二维数组类）类中成员函数有：
构造函数（创建m行n列的矩阵）；析构函数（释放动态申请数组空间）；

读入函数ReadMatrix（创建m行n列的矩阵元素的值）；

输出函数WriteMatrix（输出m行n列的矩阵元素的值，每个元素占5个字符宽度 ）；

转置函数void Transpose(Matrix& B)（将当前对象矩阵转置为一个n行m列的B矩阵）。

在main()函数中输入m,n的值创建m行n列的矩阵A，矩阵B是A的转置矩阵。

int main()
{
    int m, n;
    cin >> m >> n;
    Matrix A(m, n);
    A.ReadMatrix();
    A.WriteMatrix();
    Matrix B(n, m);
    A.Transpose(B);
    B.WriteMatrix();
    system("pause");
    return 0;
}
输入格式:
第一行：读入连个整数m,n (中间空格隔开）
接下m行，每行读入n个整数（读入A矩阵）

输出格式:
先输出A矩阵
后输出B矩阵（A的转置矩阵）

输入样例:
在这里给出一组输入。例如：

4 3
1 2 3
2 3 4
3 4 5
4 5 6
输出样例:
在这里给出相应的输出。例如：

    1    2    3
    2    3    4
    3    4    5
    4    5    6
    1    2    3    4
    2    3    4    5
    3    4    5    6
*/
#include <iostream>
#include <iomanip>
using namespace std;

class Matrix
{
    public:

    // 创建一个二维数组
    Matrix(int m, int n)
    {
        this->m = m;
        this->n = n;
        data = new int*[m];
        for (int i = 0; i < m; i++)
        {
            data[i] = new int[n];
        }
    }

    // 写入矩阵
    void ReadMatrix()
    {
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> data[i][j];
            }
        }
    }

    void WriteMatrix(){
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << setw(5) << data[i][j];
            }
            cout << endl;
        }
    }
    
    // 转置函数
    void Transpose(Matrix& B)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                B.data[i][j] = data[j][i];
            }
        }
    }

    private:
        int m, n;
        int **data;


};
int main()
{
    int m, n;
    cin >> m >> n;
    Matrix A(m, n);
    A.ReadMatrix();
    A.WriteMatrix();
    Matrix B(n, m);
    A.Transpose(B);
    B.WriteMatrix();
    system("pause");
    return 0;
}