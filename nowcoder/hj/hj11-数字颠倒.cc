#include <iostream>
#include <string>
using namespace std;
int main()
{
    string num;
    cin >> num;
    string ret;
    for (int i = num.size() - 1; i >= 0; i--)
    {
        ret += num[i];
    }
    cout << ret;
}
// 输入：
// 1516000
// 复制
// 输出：
// 0006151