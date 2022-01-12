#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
typedef pair<string, int> PAIR; // pair声明在utility中，可能被包含在map中
// struct cmByValue
// {
//     bool operator()(const PAIR &x, const PAIR &y)
//     {
//         return x.second < y.second;
//     }
// };
int main()
{
    vector<PAIR> m;
    int count;
    cin >> count;
    while (count--)
    {
        string s;
        cin >> s;
        int idx(0);   //记录数字字符串第一个index
        int value(0); //记录磁盘容量大小，以MB为单位
        for (int i = 0; i < s.size(); i++)
        {
            switch (s[i])
            {
            case 'M':
                value += stoi(s.substr(idx, i - idx));
                idx = i + 1;
                break;
            case 'G':
                value += stoi(s.substr(idx, i - idx)) << 10;
                idx = i + 1;
                break;
            case 'T':
                value += stoi(s.substr(idx, i - idx)) << 20;
                idx = i + 1;
                break;

            default:
                break;
            }
        }
        m.emplace_back(make_pair(s, value));
    }
    sort(m.begin(), m.end(), [](const PAIR &x, const PAIR &y)
         { return x.second < y.second; }); //可以直接用方法，可以使用结构体中运算符重载的方式,也可使用[](){} lambda, 不能直接sort a map
    for (auto p : m)
    {
        cout << p.first << endl;
    }
}

// 输入

// 3

// 2G4M

// 3M2G

// 1T

// 输出

// 3M2G

// 2G4M

// 1T