#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main()
{
    int n1;
    while (cin >> n1)
    {
        set<int, bool (*)(int, int)> nums([](int a, int b)
                                          { return a < b; }); //不能<=否者set会将相等的也插入,容器template内置comparetor
        int n2;
        while (n1--)
        {
            int n;
            cin >> n;
            nums.emplace(n);
        }
        cin >> n2;
        while (n2--)
        {
            int n;
            cin >> n;
            nums.emplace(n);
        }
        for (auto n : nums)
            cout << n;
        cout<<endl;
    }
}