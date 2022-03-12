#include <vector>
#include <deque>
using namespace std;
class Solution
{
    vector<int> maxInWindows(const vector<int> &num, unsigned int size)
    {
        vector<int> ret;
        deque<int> window; //保持单调递减的队列，元素为index
        int len = num.size();
        for (int i = 0; i < len; i++)
        {
            while (!window.empty() && window.back() <= num[i])//清除小于当前遍历到的元素，保持单调
                window.pop_back();
            window.emplace_back(i);
            if (i - window.front() + 1 > size)//清除超出范围的头部
                window.pop_front();
            if (i + 1 > size)
                ret.emplace_back(window.front());
        }
        return ret;
    }
};