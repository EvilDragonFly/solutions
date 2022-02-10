#include <iostream>
#include <vector>
#include <set>
using namespace std;
struct Node
{
    int val;
    vector<int> sons;
};
void kill(vector<int> &pids, vector<int> &ppids, vector<Node> &nodes) //传引用的方式杜绝堆上分配
{
    set<int> s; //用来标记节点是否已经添加
    for (auto n : pids)
        if (s.count(n) == 0)
        {
            s.emplace(n);
            Node nod{n, vector<int>{}}; //匿名对象的构造，使用{},不使用()，详情见effective c++
            nodes.emplace_back(nod);
        }

    for (int i = 0; i < ppids.size(); i++)
    {
        int pid = pids[i];
        int ppid = ppids[i];
        if (s.count(ppid) == 0) //新节点
        {
            s.emplace(ppid);
            Node nod{ppid, vector<int>{pid}};
            nodes.emplace_back(nod);
        }
        else
            for (auto &node : nodes)
                if (node.val == ppid)
                {
                    //更新旧节点的子节点集合
                    node.sons.emplace_back(pid);
                    break;
                }
    }
}
void getdescendants(vector<Node> &tree, int val, vector<int> &descendants)
{
    descendants.emplace_back(val);
    for (auto node : tree)                      //待优化查询
        if (node.val == val)
            for (auto n : node.sons)
                getdescendants(tree, n, descendants);
}
int main()
{
    vector<int> pids = {1, 3, 10, 5};
    vector<int> ppids = {3, 0, 5, 3};
    vector<Node> Tree;
    kill(pids, ppids, Tree);    //构建树结构
    int tokill = 5;
    vector<int> ans;
    getdescendants(Tree, tokill, ans);
    for (auto n : ans)
        cout << n << " ";
}
// Given n processes, each process has a unique PID (process id) and its PPID (parent process id).

// Each process only has one parent process, but may have one or more children processes. This is just like a tree structure. Only one process has PPID that is 0, which means this process has no parent process. All the PIDs will be distinct positive integers.

// We use two list of integers to represent a list of processes, where the first list contains PID for each process and the second list contains the corresponding PPID.

// Now given the two lists, and a PID representing a process you want to kill, return a list of PIDs of processes that will be killed in the end. You should assume that when a process is killed, all its children processes will be killed. No order is required for the final answer.

// Input:
// pid =  [1, 3, 10, 5]
// ppid = [3, 0, 5, 3]
// kill = 5
// Output: [5,10]
// Explanation:
//            3
//          /   \
//         1     5
//              /
//             10
// Kill 5 will also kill 10.