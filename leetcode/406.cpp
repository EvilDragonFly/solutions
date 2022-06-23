#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> ret;
    vector<vector<int>> ReconstructQueue(const vector<vector<int>> &people)
    {
        vector<vector<int>> ppl = people;
        // 优先身高倒序，再人头数升序     （身高优先插入时不会对前面的高个有影响）
        auto comp = [](vector<int> &a, vector<int> &b) { return a[0] == b[0] ? a[1] < b[1] : a[0] > b[0]; };
        sort(ppl.begin(), ppl.end(), comp);
        for (auto p : ppl) {
            ret.insert(ret.begin() + p[1], p);
        }
        return ret;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> people = {{8, 0}, {4, 4}, {8, 1}, {5, 0}, {6, 1}, {5, 2}};
    vector<vector<int>> out = s.ReconstructQueue(people);
}