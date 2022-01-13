#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, pair<int, int>> PAIR;
int main()
{
    vector<PAIR> v; //记录编号，身高和体重
    int num;
    cin >> num;
    int tmp = num;
    vector<int> height;
    while (tmp--)
    {
        int h;
        cin >> h;
        height.emplace_back(h);
    }
    vector<int> weight;
    while (num--)
    {
        int w;
        cin >> w;
        weight.emplace_back(w);
    }
    for (int i = 0; i < height.size(); i++)
    {
        auto hw = make_pair(height[i], weight[i]);
        v.emplace_back(make_pair(i + 1, hw));
    }
    sort(v.begin(), v.end(), [](PAIR x, PAIR y)
         { return x.second.first < y.second.first || (x.second.first == y.second.first && x.second.second <= y.second.second); }); //稳定排序列出为true的条件
    for (auto p : v)
    {
        cout << p.first << " ";
    }
}
// 4

// 100 100 120 130

// 40 30 60 50

// 输出

// 2 1 3 4

// 说明

// 输出的第一个数字2表示此人原始编号为2，即身高为100，体重为30的这个人。由于他和编号为1的人身高一样，但体重更轻，因此要排在1前面。