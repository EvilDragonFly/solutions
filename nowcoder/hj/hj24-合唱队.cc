#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int toleft(vector<int> &hs, int i, vector<int> des)
{ //队列hs中i左边能与ls组成的最长降序队列的长度
    if (i == 0)
        return des.size();
    int x1 = toleft(hs, i - 1, des); //需要考虑函数对des的影响对后续操作的影响
    if (hs[i - 1] < des.back())
    {
        des.emplace_back(hs[i - 1]);
        int x2 = toleft(hs, i - 1, des);
        return max(x1, x2);
    }
    return x1;
}
int toright(vector<int> &hs, int i, vector<int> des)
{
    if (i == hs.size() - 1)
        return des.size();
    int x1 = toleft(hs, i + 1, des);
    if (hs[i + 1] < des.back())
    {
        des.emplace_back(hs[i + 1]);
        int x2 = toleft(hs, i + 1, des);
        return max(x1, x2);
    }
    return x1;
}
int main()
{
    int num;
    while (cin >> num)
    {
        vector<int> hs;
        while (num--)
        {
            int h;
            cin >> h;
            hs.push_back(h);
        }
        vector<int> ns; //以各个同学为top的最长合唱队列
        for (int i = 0; i < hs.size(); i++)
        {
            vector<int> des1, des2;
            int n = toleft(hs, i, des1) + toright(hs, i, des2) + 1;
            ns.push_back(n);
        }
        int ret = *max_element(ns.begin(), ns.end());
        cout << ret << endl;
    }
}

// 解决方案，求出最长合唱队形
// 对于合唱队中最高队员，其位置为i,则合唱队列长度为dp[i]=toleft[i]+toright[i]+1;
// toleft记录该队员左边最长升序队列，toright反之