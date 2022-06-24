#include <bits/stdc++.h>
using namespace std;
// ##堆  ##优先队列
class Solution {
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        vector<int> res;
        map<int, int> freq;
        using pii = std::pair<int, int>;
        // top k, min heap(小根堆) when p comp q is true , q is more close to the top, p is more close to the back
        priority_queue<pii, vector<pii>, greater<pii>> pq;

        for (auto e : nums)
            ++freq[e];

        for (auto &pair : freq) {
            pq.emplace(pair.second, pair.first);  // 类似于pq.push_back(move(make_pair(pair.first,pair.second)));
            if (pq.size() > k)
                pq.pop();
        }

        while (!pq.empty()) {
            res.emplace_back(pq.top().second);
            pq.pop();
        }

        return res;
    }
};
int main()
{
    Solution s;
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    vector<int> ret = s.topKFrequent(nums, 2);
    for (int n : ret)
        cout << n << endl;
}
