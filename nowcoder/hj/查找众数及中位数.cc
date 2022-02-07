#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <sstream>
#include <algorithm>
using namespace std;
//找出众数组成数组的中位数
int main()
{

    map<int, int> m; //记录各数字出现的次数
    int count(0);    //众数出现的次数
    string str;      //输入没有个数，只能先存入str
    getline(cin, str);
    stringstream ss(str);
    while (getline(ss, str, ' '))           //分割字符串
    {
        int num = stoi(str); //默认base=10
        m[num]++;
    }
    for (auto p : m)
    {
        count = max(count, p.second);
    }
    vector<int> ns; //众数数组
    for (auto p : m)
    {
        if (p.second == count)
        {
            ns.push_back(p.first);
        }
    }
    sort(ns.begin(), ns.end());
    int len = ns.size();
    int i1 = (len - 1) / 2;
    int i2 = (len + 1) / 2;
    if (ns.size() % 2 == 0)
    {
        cout << (ns[i1] + ns[i2]) / 2;
    }
    else
    {
        cout << ns[i1];
    }
}
//https://blog.csdn.net/f_h_h/article/details/121390332