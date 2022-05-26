#include <bits/stdc++.h>
using namespace std;

//直接按父子串判定{父串包含所有子串的字母，且各字母相对顺序一致}，只需一边遍历，遍历过程中查看是否存在不合规的大写字母
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
                else if (query[qi] < 'a')//注意大写字母小于小写字母
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
