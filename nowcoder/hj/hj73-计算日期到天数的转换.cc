#include <iostream>
#include <numeric>
using namespace std;
int main()
{
    int y, m, d;
    cin >> y >> m >> d;
    int a[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0)                 //leap year condition
        a[1] = 29;
    int ret(0);
    ret = accumulate(a, a + m - 1, 0) + d;                          // accumulate函数
    cout << ret;
}