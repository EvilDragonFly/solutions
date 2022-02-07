#include <bits/stdc++.h>
using namespace std;
// 并查集   注意动态数组初始化，()和{}用于内置类型和自定义类型初始化的区别
class Solution
{
public:
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int num = isConnected.size();
        // bool *visited = new bool[num]()
        bool *visited = new bool[num]{0};            //动态数组初始化 或可写为bool *visited = new bool[num]();
        cout << visited[0] << visited[1] << visited[2] << visited[3] << endl;
        int ret(0);
        for (int i = 0; i < num; i++)
        {
            if (!visited[i])
            {
                dfs(isConnected, visited, i);
                ret++;
            }
        }
        return ret;
    }
    void dfs(vector<vector<int>> &isConnected, bool *visited, int idx)
    {
        visited[idx] = true;
        for (int i = 0; i < isConnected.size(); i++)
        {
            if (i != idx && isConnected[idx][i] == 1 && !visited[i])
                dfs(isConnected, visited, i);
        }
    }
};
int main()
{
    vector<vector<int>> isConnected = {{1, 0, 0, 1}, {0, 1, 1, 0}, {0, 1, 1, 1}, {1, 0, 1, 1}};
    Solution s;
    int ret = s.findCircleNum(isConnected);
    cout << ret;
}