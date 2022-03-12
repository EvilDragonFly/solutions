#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int findKth(vector<int> a, int n, int K)
    {
        // write code here
        nth_element(a.begin(), a.end() - K, a.end());
        return a[a.size() - K];
    }
};