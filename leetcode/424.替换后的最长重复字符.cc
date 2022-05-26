#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        int nums[26] = {0}; //记录区间中各字符出现的次数
        int maxn = 0;
        int left = 0, right = 0;
        int len = s.length();
        while (right < len)
        {
            nums[s[right] - 'A']++;
            maxn = max(maxn, nums[s[right] - 'A']);
            if (right - left + 1 - maxn > k)
            {
                nums[s[left] - 'A']--;
                left++;
            }
            right++;
        }
        return right - left;
    }
};
int main()
{
    Solution s;
    cout<<s.characterReplacement("ABAB",2);
}
// 输入：s = "ABAB", k = 2
// 输出：4
// 解释：用两个'A'替换为两个'B',反之亦然。


//难点1.计算区间中出现次数最多的字符的出现次数   用长度为26的数组更新记录各字符长度，用maxn更新最大值
//难点2.如何遍历整个字符串 双指针，维持窗口单调递增