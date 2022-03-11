#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> sum(vector<int> nums)
    {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int len = nums.size();
        int sum(0);
        for (int i = 0; i < len - 2; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])        //除去重复的
                continue;
            if (nums[i] * 3 > 0)
                break;
            int target = 0 - nums[i];
            int left = i + 1;
            int right = len - 1;
            while (left < right)
            {
                if (nums[left] + nums[right] == target)
                {
                    ans.emplace_back(vector<int>{nums[i], nums[left], nums[right]});
                    while (left < right && nums[left + 1] == nums[left])
                        left++;
                    left++;
                    while (left < right && nums[right--] == nums[right])
                        right--;
                    right--;
                }
                else if (nums[left] + nums[right] < target)
                {
                    left++;
                }
                else
                {
                    right--;
                }
            }
        }
        return ans;
    }
};
int main()
{
    vector<int> input{-1, 0, 1, 2, -1, -4};
    Solution s;
    auto ans = s.sum(input);
    for (auto p : ans)
    {
        for (auto n : p)
        {
            cout << n << ",";
        }
        cout << endl;
    }
}