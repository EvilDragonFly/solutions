#include <vector>
#include <string>
using namespace std;
class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1)
            return s;
        vector<string> strs(numRows);
        int targetrow(0);
        int len = s.size();
        int idx = len;
        bool godown = false;
        while (idx--)
        {
            strs[targetrow] += s[len - idx - 1];
            if (targetrow == 0 || targetrow == numRows - 1)
                godown = !godown; //改变方向
            if (godown)
                targetrow++;
            else
                targetrow--;
        }
        string ans;
        for (auto str : strs)
            ans += str;
        return ans;
    }
};