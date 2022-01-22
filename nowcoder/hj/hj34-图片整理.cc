#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main()
{
    string str;
    while (cin >> str)
    {
        sort(str.begin(), str.end());           //字符串也可以像容器一样被相关工具函数处理，如sort,reverse等等
        cout << str << endl;
    }
}