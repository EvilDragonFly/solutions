#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n;
    while (cin >> n)
    {
        int ret(0);
        if (n == 0)
            continue;
        while (n >= 3)
        {
            int full = n / 3;
            ret += full;
            n -= full * 2;          // 需要花费3*full个空汽水瓶，但是能回收full个
        }
        if (n == 2)
            ret += 1;
        cout << ret << endl;
    }
}