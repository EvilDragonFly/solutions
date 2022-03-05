// Wuchangye w00560594对所有人说说： 08:05 PM
// 给定一个字符串s和一个字符串p，请问最少去掉s中的多少个字符，才能使得p是s的子串呢？
// 解答要求时间限制：1000ms, 内存限制：100MB

// 输入
// 两行，第一行为字符串s，第二行为字符串p。(s和p只包含小写英文字母,s的长度不超过2000,p的长度不超过10,且保证有解）

// 输出
// 最少去掉的字符个数。

// 样例
// 输入样例 1
//     axb
//     ab
// 输出
//     1
// 输入样例 2
//     axabc
//     abc
// 输出
//     0
// 输入样例 3
//     axbacxbc
//     abc
// 输出
//     2
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool isFatherStr(string f, string s)
{                          // f"包含"s
    int idx(s.size() - 1); //字符在s的index
    for (int i = f.size(); i >= 0 && idx >= 0; i--)
    {
        if (f[i] == s[idx])
            idx--;
    }
    if (idx < 0)
        return true;
    else
        return false;
}
int main()
{
    string s, p;
    getline(cin, s);
    getline(cin, p);
    vector<int> startIndex;
    vector<int> endIndex;
    int ret(s.size() - p.size());
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == p.front())
            startIndex.emplace_back(i);
        else if (s[i] == p.back())
            endIndex.emplace_back(i);
    }
    for (auto sidx : startIndex)
    {
        int len = p.size() + ret;
        for (auto eidx : endIndex)
        {
            if (eidx - sidx + 1 > p.size() && eidx - sidx + 1 <= len && isFatherStr(s.substr(sidx, eidx - sidx + 1), p))
            {
                ret = min<int>(eidx - sidx + 1 - p.size(), ret); // explicitly mention the template argument
                break;
            }
        }
    }
    cout << ret;
}
//最短"父串"的首尾字符一定和子串一致
//每次从首字符开始，寻找满足长度差距(不小于子串长度，小于之前找到的父串长度)的尾字符，判断是否满足父子关系，如果是，就直接更新ret值。
