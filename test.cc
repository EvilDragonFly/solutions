#include <bits/stdc++.h>
using namespace std;

//直接按父子串判定，然后查看两字符串中大写字母的个数
class Solution
{
public:
    vector<bool> camelMatch(vector<string> &queries, string pattern)
    {
        vector<bool> ret; //初始化时指定长度和reserve指定容量不一样
        ret.reserve(queries.size());
        for (auto query : queries)
        {
            int qi = query.size() - 1;
            int pi = pattern.size() - 1;
            bool wrongbig = false;
            while (qi >= 0 && pi >= 0)
            {
                if (query[qi] == pattern[pi])
                {
                    pi--;
                    // qi--;
                }
                else if (query[qi] < 'a')
                {
                    // ret.push_back(false);
                    wrongbig = true;
                    break;
                }
                qi--;
            }
            if (!wrongbig)
                for (int i = 0; i < qi; i++)
                {
                    if (query[i] < 'a')
                    {
                        // ret.push_back(false);
                        wrongbig = true;
                        break;
                    }
                }
            if (pi >= 0 || wrongbig)
                ret.push_back(false);

            else
                ret.push_back(true);
        }
        return ret;
    }
};
int main()
{
    Solution s;
    vector<string> queries = {"FooBar"};
    vector<bool> ret = s.camelMatch(queries, "FB");
    for (auto a : ret)
    {
        cout << boolalpha << a << endl;
    }
}
