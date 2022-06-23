#include <bits/stdc++.h>
using namespace std;
// 并查集||dfs   注意动态数组初始化，()和{}用于内置类型和自定义类型初始化的区别
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

class Solution1 {
private:
    int n;  // 并查集边的数量
    vector<int> father;

    // 并查集初始化
    void init()
    {
        father = vector<int>(n);
        for (int i = 0; i < n; ++i)
            father[i] = i;
    }
    // 并查集里寻根的过程, 同时会更新寻根链路中各节点的根/路径压缩
    int find(int u)
    {
        return u == father[u] ? u : father[u] = find(father[u]);
    }
    // 将v->u 这条边加入并查集
    void join(int u, int v)
    {
        u = find(u);
        v = find(v);
        if (u == v)
            return;
        father[v] = u;
    }
    // 判断 u 和 v是否找到同一个根，本题用不上
    bool same(int u, int v)
    {
        u = find(u);
        v = find(v);
        return u == v;
    }

public:
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        n = isConnected.size();
        init();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j])
                    join(i, j);
            }
        }
        // 此时已经并查集已经把边链接好了

        unordered_set<int> uset;  // 统计有多少个没有链接的省份
        for (int i = 0; i < n; i++) {
            uset.insert(find(i));
        }
        return uset.size();
    }
};
int main()
{
    vector<vector<int>> isConnected = {{1, 0, 0, 1}, {0, 1, 1, 0}, {0, 1, 1, 1}, {1, 0, 1, 1}};
    Solution s;
    int ret = s.findCircleNum(isConnected);
    cout << ret;
}
