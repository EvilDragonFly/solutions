#include <iostream>
#include <vector>
#include <tuple>
using namespace std;
int main()
{

    int j, i; //苹果数,盘子数
    while (cin >> j >> i)
    {
        vector<vector<int>> dp(i + 1, vector<int>(j + 1, 0));           //初始化
        for (int x = 0; x <= i; x++)                                    //动态规划采用dp数组记录计算结果，从下到上，能比递归有效减少计算已计算过的结果
            for (int y = 0; y <= j; y++)
            {
                if (x <= 1 || y <= 1)
                    dp[x][y] = 1;
                else
                    dp[x][y] = dp[x - 1][y] + (x > y ? 0 : dp[x][y - x]); // x盘子数，y苹果数
            }
        cout << dp[i][j] << endl;
    }
}
//初始状态转移矩阵dp[n][m],dp[i][j]表示i个盘子放j个苹果的放法；

// 状态转移方程为dp[i][j]=dp[i-1][j]+ i>j?0:dp[i][j-i]          //分为i个盘子和i-1个盘子，i个盘子意味着每个盘子都有一个苹果
// dp[0][x]= dp[x][0] = dp [1][x] = dp[x][1] = 1