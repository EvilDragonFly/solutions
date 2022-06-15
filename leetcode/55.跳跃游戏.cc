#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        if (nums.size() == 0)
            return true;

        int cur = nums[0], i = 1;
        for (; cur != 0 && i < nums.size(); i++)
        {
            cur--;
            if (cur < nums[i])
                cur = nums[i];
        }
        return i == nums.size();
    }
};
int main()
{
    vector<int> input{3, 2, 1, 0, 4};
    Solution s;
    cout << boolalpha << s.canJump(input);
}
// 能否到达最终点