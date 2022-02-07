#include <iostream>
#include <vector>
#include <unordered_map>
#include <cctype>
#include <algorithm>
using namespace std;
int prettynum(string str)
{ //计算一个字符串最大漂亮度,统计各字符个数，最多的赋值26，依次递减
    unordered_map<char, int> umap;
    for (auto ch : str)
    {
        char c = tolower(ch);
        umap[c]++;
    }
    vector<pair<char, int>> chs(umap.begin(), umap.end());              //要进行排序首先需要将map转vector
    sort(chs.begin(), chs.end(), [](pair<char, int> a, pair<char, int> b)
         { return a.second >= b.second; });
    int base = 26;
    int ans(0);
    for (auto p : chs)
        ans += (base--) * p.second;
    return ans;
}
int main()
{
    int N;
    while (cin >> N)
    {
        while (N--)
        {
            string str;
            cin >> str;
            cout << prettynum(str) << endl;
        }
    }
}