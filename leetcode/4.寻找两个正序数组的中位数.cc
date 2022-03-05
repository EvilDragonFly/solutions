#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        nums1.insert(nums1.end(), nums2.begin(), nums2.end());
        int len = nums1.size();
        int idx = (len - 1) / 2;
        nth_element(nums1.begin(), nums1.begin() + idx, nums1.end());
        if (len % 2 == 0)
        {
            nth_element(nums1.begin() + idx, nums1.begin() + 1, nums1.end());   //注意nth_element会破坏之前调用排好序的部分，所以这里必须从idx开始
            return (nums1[idx] + nums1[idx + 1]) / 2.0;
        }
        return nums1[idx];
    }
};
int main()
{
    int count1, count2;
    cin >> count1 >> count2;
    vector<int> nums1(count1), nums2(count2); // 大括号小括号初始化有差异，大括号中数字会被认为是元素值
    for (auto &n : nums1)
        cin >> n;
    for (auto &n : nums2)
        cin >> n;
    Solution s;
    cout << "中位数:" << s.findMedianSortedArrays(nums1, nums2) << endl;
}