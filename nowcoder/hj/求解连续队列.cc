#include <iostream>
using namespace std;
int main()
{
    // 考验等差数列
    int S, N;
    cin >> S >> N;
    // S = N*a + (N-1)!,a为队列第一个数字
    int na = S - N * (N - 1) / 2;
    if (na < N || na % N != 0)
    { // a小于1或者a不为整数
        cout << -1 << endl;
    }
    else
    {
        int a = na / N;
        for (int i = 0; i < N; i++)
        {
            cout << a + i << " ";
        }
    }
}
// https://blog.csdn.net/meiribaofu/article/details/116710453