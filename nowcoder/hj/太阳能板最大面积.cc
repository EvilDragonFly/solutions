#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
//分治
int main()
{
    int x = 0; //记录最大值
    vector<int> nums;
    string str;
    getline(cin, str);
    string num;
    for (auto c : str)
    {
        if (c != ',')
        {
            num += c; // string可以直接加char，或者push_back，或者+string('c',num)
        }
        else
        {
            nums.push_back(stoi(num));
            num = ""; //清空
        }
    }
    nums.push_back(stoi(num));          //将最后一个数字加入
    int len = nums.size();
    for (int i = 0; i < len; i++) //遍历每一根柱子
    {
        int area(0);
        for (int left = i - 1; left >= 0; left--)
        {
            if (nums[left] < nums[i])
            {
                break;
            }
            else
            {
                area += nums[i];                    //加的是该柱子的长度
            }
        }
        for (int right = i + 1; right < len; right++)
        {
            if (nums[right] < nums[i])
            {
                break;
            }
            else
            {
                area += nums[i];
            }
        }
        x = max(area, x);
    }
    cout << x << endl;
}
// 输入

// 10,9,8,7,6,5,4,3,2,1

// 输出

// 25

// https://blog.csdn.net/u013015065/article/details/78960224