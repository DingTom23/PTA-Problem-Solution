#include <iostream>
#include <vector>
using namespace std;

int main() {

    int n, m, k;
    cin >> n >> m >> k;

    // 读取矩阵 A
    vector<vector<int>> A(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> A[i][j];
        }
    }

    // 读取矩阵 B
    vector<vector<int>> B(m, vector<int>(k));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < k; j++) {
            cin >> B[i][j];
        }
    }

    // 准备结果矩阵 C，其尺寸为 n x k
    vector<vector<int>> C(n, vector<int>(k, 0));

    // 计算矩阵乘法 C = A * B
    // C[i][j] = A[i][0]*B[0][j] + A[i][1]*B[1][j] + ... + A[i][m-1]*B[m-1][j]
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            int sum = 0;
            for (int p = 0; p < m; p++) {
                sum += A[i][p] * B[p][j];
            }
            C[i][j] = sum;
        }
    }

    // 输出结果矩阵 C
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            cout << C[i][j];
            if (j < k - 1) cout << " ";
        }
        cout << "\n";
    }

    return 0;
}