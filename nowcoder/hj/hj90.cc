#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    string ip;
    while (cin >> ip)
    {
        vector<int> dots; //记录点的位置
        for (int i = 0; i < ip.length(); i++)
        {
            if (ip[i] == '.')
            {
                dots.push_back(i);
            }
        }
        if (dots.size() != 3 || dots[0] == 0 || dots[2] == ip.size() - 1)
        {
            cout << "NO" << endl;
            continue;
        }
        else
        {
            vector<int> nums;
            int start = 0; //记录一个数字的起始位置
            for (auto i : dots)
            {
                string s = ip.substr(start, i - start); //除去点号
                int num = stoi(s, nullptr, 0);
                nums.push_back(num);
                start = i + 1;
            }
            string s = ip.substr(dots[2] + 1);
            nums.push_back(stoi(s, nullptr, 0));
            if (nums[0] <= 0)
            {
                cout << "NO";
                continue;
            }
            for (auto i : nums)
            {
                if (i < 0 || i > 255)
                {
                    cout << "NO" << endl;
                    goto label;
                }
            }
            cout << "YES" << endl;
        label:
            continue;
        }
    }
}