#include <iostream>
using namespace std;
int main()
{
    float num;
    cin >> num;
    int n = (int)num;
    if ((num - n) >= 0.5)
        cout << n + 1;
    else
        cout << n;
}
// 输入：
// 5.5
// 复制
// 输出：
// 6
// 复制
// 说明：
// 0.5>=0.5，所以5.5需要向上取整为6