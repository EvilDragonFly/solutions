#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
int main()
{
    int count(0);
    while (cin >> count)
    {
        vector<int> nums;
        set<int> s; //删除重复的数字
        while (count--)
        {
            int n;
            cin >> n;
            if (s.find(n) == s.end())
            { //只处理没有重复的数字
                s.insert(n);
                nums.push_back(n);
            }
        }
        sort(nums.begin(), nums.end());
        for (auto n : nums)
            cout << n << endl;
        // nums.clear(); 将nums置与while的scope下不需要clear
    }
}