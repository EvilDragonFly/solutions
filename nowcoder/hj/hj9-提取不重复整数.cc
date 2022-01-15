#include <iostream>
#include <string>
#include <set>
using namespace std;
int main()
{
    string num;
    getline(cin, num);
    set<char> s;
    string ret;
    for (int i = num.size() - 1; i >= 0; i--)
    {
        if (s.count(num[i]) == 0)
        {
            s.emplace(num[i]);
            ret += num[i];
        }
    }
    cout << ret;
}

// 输入：
// 9876673
// 复制
// 输出：
// 37689