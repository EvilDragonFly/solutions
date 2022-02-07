#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    int count;
    while (cin >> count)
    {
        vector<string> strs(count);
        for (auto &str : strs)
            cin >> str;
        string target;
        cin >> target;
        string targetTmp = target;
        sort(targetTmp.begin(), targetTmp.end());
        vector<string> ans; //兄弟单词
        for (auto str : strs)
        {
            string temp = str;
            sort(temp.begin(), temp.end());
            if (str != target && temp == targetTmp)
                ans.emplace_back(str);
        }
        sort(ans.begin(), ans.end());
        int k;
        cin >> k;
        cout << ans.size() << endl;
        if (k < ans.size())
            cout << ans[k - 1] << endl;
    }
}