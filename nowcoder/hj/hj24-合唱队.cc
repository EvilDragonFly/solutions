#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int num;
    while (cin >> num)
    {
        vector<int> hs(num);
        vector<int> left(num, 1); //记录对应点左边的最长ascending queue的长度
        vector<int> right(num, 1);
        for (auto &h : hs)
        {
            cin >> h;
        }
        for (int i = 0; i < num; i++) // ---->
        {
            for (int j = 0; j < i; j++)
            {
                if (hs[j] < hs[i])
                {
                    left[i] = max(left[j] + 1, left[i]);
                }
            }
        }
        for (int i = num - 1; i >= 0; i--) // <----
        {
            for (int j = num - 1; j > i; j--)
            {
                if (hs[j] < hs[i])
                {
                    right[i] = max(right[j] + 1, right[i]);
                }
            }
        }
        vector<int> ns; //以各个同学为top的最长合唱队列
        for (int i = 0; i < num; i++)
        {
            int n = left[i] + right[i] - 1;
            ns.emplace_back(n);
        }
        int ret = *max_element(ns.begin(), ns.end());
        cout << num - ret << endl;
    }
}
// 解决方案，求出最长合唱队形
// 对于合唱队中最高队员，其位置为i,则合唱队列长度为dp[i]=toleft[i]+toright[i]+1;
// toleft记录该队员左边最长升序队列，toright反之