class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        nums1.insert(nums1.end(), nums2.begin(), nums2.end());
        int len = nums1.size();
        int idx1 = (len - 1) / 2;
        nth_element(nums1.begin(), nums1.begin() + idx1, nums1.end());
        if (len % 2 == 0)
        {
            int idx2 = (len + 1) / 2;
            nth_element(nums1.begin(), nums1.begin() + idx2, nums1.end());
            for (auto n : nums1)
                cout << "num:" << n << endl;
            return (nums1[idx1] + nums1[idx2]) / 2.0;
        }
        return nums1[idx1];
    }
};