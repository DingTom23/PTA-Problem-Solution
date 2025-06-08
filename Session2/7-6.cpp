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