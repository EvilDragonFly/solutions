#include <iostream>
#include <set>
using namespace std;
class Solution
{
public:
    
    int getNext(int n)
    {
        int ret(0);
        while (n > 0)
        {
            int d = n % 10;
            n /= 10;
            ret += d * d;
        }
        return ret;
    }
    // Detect Cycles with a HashSet
    bool isHappy(int n)
    {
        set<int> mysets;
        while (n != 1 && mysets.count(n) == 0)
        {
            mysets.emplace(n);
            n = getNext(n);
        }
        return n == 1;
    }
    // Floyd's Cycle-Finding Algorithm,快慢指针；Space complexity : O(1)
    bool isHappy(int n)
    {
        int slow = n, fast = getNext(n);
        while (fast != 1 && slow != fast)
        {
            slow = getNext(slow);
            fast = getNext(getNext(fast));
        }
        return fast == 1;
    }
    // Hardcoding the Only Cycle (Advanced)
    bool isHappy(int n)
    {
        while (n != 1 && n != 4)
            n = getNext(n);
        return n == 1;
    }
};
int main()
{
    Solution s;
    cout << boolalpha << s.isHappy(116);
}
// https://leetcode.com/problems/happy-number/solution/