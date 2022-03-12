#include <bits/stdc++.h>
using namespace std;

// Definition for an interval.
struct Interval
{
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution
{
public:
    //按start进行排序，然后一个个的加到结果res中。
    //如果待加入节点的start <= res.back().end 说明相交，直接更新end，取节点end和当res.back().end中的较大值。
    //如果start > res.back()则不相交 直接加入res中。
    //第一个节点，也直接加入res中
    vector<Interval> merge(vector<Interval> &intervals)
    {
        sort(intervals.begin(), intervals.end(), [](Interval x, Interval y)
             { return x.start < y.start; });

        vector<Interval> res;
        for (int i = 0; i < intervals.size(); i++)
        {
            if (i == 0 || intervals[i].start > res.back().end)//将下一个区间和已经加入到res的区间进行对比
            {
                res.push_back(intervals[i]);
            }
            else
            {
                res.back().end = max(intervals[i].end, res.back().end);
            }
        }
        return res;
    }
};