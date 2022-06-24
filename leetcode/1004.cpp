#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        int ret(0);
        deque<int> dq;
        int r_k = k; // 剩余可翻转个数
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                if (r_k > 0)
                {
                    r_k--;
                }
                else
                {
                    // 翻转数字向后移一位
                    int count(0);
                    for (int i = 0; i < dq.size(); i++)
                    {
                        count++;
                        if (dq[i] == 0)
                        {
                            break;
                        }
                    }
                    dq.erase(dq.begin(), dq.begin() + count);
                }
            }

            dq.push_back(nums[i]);

            ret = ret > dq.size() ? ret : dq.size();
        }
        return ret;
    }
};
int main()
{
    Solution s;
    vector<int> nums = {0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1};
    int k = 3;
    cout << s.longestOnes(nums, k) << endl;
    nums = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    k = 2;
    cout << s.longestOnes(nums, k) << endl;
}
