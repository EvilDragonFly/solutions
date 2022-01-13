#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// 贪心算法，一步一步求部分最优解
int main()
{
    int ret(0);
    vector<int> nums1, nums2;
    int count;
    cin >> count;
    while (count--)
    {
        int num;
        cin >> num;
        nums1.push_back(num);
    }
    cin >> count;
    while (count--)
    {
        int num;
        cin >> num;
        nums2.push_back(num);
    }
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    cin >> count; //组合对数
    if (count <= 0)
        return 0;
    for (int i = 0; i < nums1.size() && count > 0; i++)
    {
        ret += nums1[i];
        for (int j = 0; j < nums2.size() && count > 0; j++)
        {
            if (i + 1 == nums1.size() || nums1[i] + nums2[j] <= nums1[i + 1] + nums2[0])
            {
                ret += nums2[j];
                count--;
            }
            else
            {
                break;
            }
        }
    }
    cout<<ret;
}

// 输入

// 3 1 1 2

// 3 1 2 3

// 2

// 输出

// 4

// 说明

// 用例中，需要取2对元素

// 取第一个数组第0个元素与第二个数组第0个元素组成1对元素[1,1];

// 取第一个数组第1个元素与第二个数组第0个元素组成1对元素[1,1];

// 求和为1+1+1+1=4，为满足要求的最小和
// ————————————————
// 版权声明：本文为CSDN博主「meiribaofu」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
// 原文链接：https://blog.csdn.net/meiribaofu/article/details/116710453