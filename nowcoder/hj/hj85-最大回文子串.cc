#include <iostream>
#include <string>
#include <ctime>
#include <algorithm>
using namespace std;
int count(string &str, int idx)
{
    int ret1 = 1;
    int offset = 1;
    while (idx + offset < str.size() && idx - offset >= 0)
    {
        if (str[idx - offset] == str[idx + offset])
            ret1 += 2;
        else
            break;
        offset++;
    }
    int ret2(0);
    offset = 1;
    while (idx + offset < str.size() && idx + 1 - offset >= 0)
    {
        if (str[idx + 1 - offset] == str[idx + offset])
            ret2 += 2;
        else
            break;
        offset++;
    }
    return max(ret1, ret2);
}
int main()
{
    clock_t begin = clock();
    string str;
    cin >> str;
    int ret(0);
    //首先考虑奇数长度的回文字符串
    int len = str.size();
    for (int i = 0; i < len; i++)
    {
        ret = max(ret, count(str, i));
    }
    cout << ret << endl;
    clock_t end = clock();
    cout << (end - begin) / CLOCKS_PER_SEC << "s";
}

// 另一个思路是回文子串的逆序字符串等于原字符串，调用algorithm中的std::reverse(str.begin(),str.end())来进行逆序操作
// 直接遍历字符串str中str.size()~1的子串，判断是否满足条件