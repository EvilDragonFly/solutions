#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// ##贪心 ##sort
class Solution {
public:
    string largestNumber(vector<int> &nums)
    {
        auto comp = [](int i, int j) {
            string s1 = to_string(i);
            string s2 = to_string(j);
            return s1 + s2 >= s2 + s1;
        }; 
        sort(nums.begin(), nums.end(), comp);
        string ret;
        for (auto n : nums) {
            ret += to_string(n);
        }
        return ret;
    }
};
int main()
{
    vector<int> nums = {3, 30, 34, 5, 9};
    Solution s;
    cout << s.largestNumber(nums);
}