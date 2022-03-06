#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        // int sum = 0;
        // int ans = 0;
        // for (auto num : nums)
        // {
        //     if (sum > 0)
        //         sum += num;
        //     //更换子数组的初始位置
        //     else
        //         sum = num;
        //     ans = max(ans, sum);

        //     return ans;
        // }
        for(int i=1;i<nums.size();i++){
            nums[i] += max(nums[i-1],0);
        }
        return *max_element(nums.begin(),nums.end());
    }
};