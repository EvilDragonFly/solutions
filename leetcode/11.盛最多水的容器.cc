#include <algorithm>
using namespace std;
class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int ans(0);
        for (int i = 0; i < height.size(); i++)
        {
            ans = max(ans, getArea(height, i));
        }
        return ans;
    }
    int getArea(vector<int> &height, int idx)
    { //矩形高度为height[idx],且边界为idx
        int h = height[idx];
        int len = height.size();
        int leftIdx(0), rightIdx(len - 1);
        for (int i = 0; i <= idx; i++)
        {
            if (height[i] >= h)
            {
                leftIdx = i;
                break;
            }
        }
        for (int i = len - 1; i >= idx; i--)
        {
            if (height[i] >= h)
            {
                rightIdx = i;
                break;
            }
        }
        int width1 = idx - leftIdx;
        int width2 = rightIdx - idx;
        return max(width1, width2) * h;
    }
};