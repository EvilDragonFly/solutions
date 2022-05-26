#include <vector>
#include <algorithm>
#include <iostream>
#include <climits>
using namespace std;
class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        //因为三个数之和，不太好移动，我们固定第一个数，找到这个数和任意两个数组成的距离target最近的组合。
        //然后把这个数往前移动，继续寻找
        sort(nums.begin(), nums.end());
        int p = 0;
        int q = 0;
        int sum = 0;
        int dif = 0;          //差值
        int mindif = INT_MAX; //最小差值
        int len = nums.size();
        int ret = INT_MAX;
        for (int first = 0; first < len - 2; first++)
        {
            p = first + 1;
            q = len - 1;
            while (p < q)
            {
                sum = nums[p] + nums[q] + nums[first];
                dif = abs(sum - target);
                if (dif < mindif)
                    ret = sum;
                mindif = mindif > dif ? dif : mindif;
                if (sum > target)
                    q--;
                else if (sum < target)
                    p++;
                else
                    return sum;
            }
        }
        return ret;
    }
};
int main()
{
    vector<int> nums{1, 2, 5, 10, 11};
    int target = 12;
    Solution s;
    int res = s.threeSumClosest(nums, target);
    cout << res;
}