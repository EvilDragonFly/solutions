#include <iostream>
#include <string>
using namespace std;
int main()
{
    //贪心算法
    //一步一步来找到target字符在source字符串的位置
    string target, source;
    cin >> target >> source;
    int i = source.size() - 1, j = target.size() - 1;
    for (; i >= 0 && j >= 0; i--)
    {
        if (source[i] == target[j])
        {
            j--;
        }
    }
    if (j >= 0)
    {
        cout << -1;
    }
    else
    {
        cout << i + 1;
    }
}
// https://blog.csdn.net/meiribaofu/article/details/116710453
//  输入

// abc

// abcaybec

// 输出

// 3