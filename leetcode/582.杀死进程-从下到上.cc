#include <iostream>
#include <vector>
#include <map>
using namespace std;
// 由于父亲可有多个子，儿子只有一个父亲，故采用从下到上的方式比较合适
void build_relation(vector<int> &pids, vector<int> &ppids, map<int, int> &son_dads) //传引用的方式杜绝堆上分配
{
    for (int i = 0; i < ppids.size(); i++)
    {
        int pid = pids[i];
        int ppid = ppids[i];
        son_dads[pid] = ppid;
    }
}
void getdescendants(map<int, int> &son_dads, int dad, vector<int> &descendants)
{
    descendants.emplace_back(dad);      //将自己也包含进去
    for (auto son_dad : son_dads)
    {
        int son = son_dad.first;
        while (son_dads[son] != dad && son_dads[son] != 0)  //向上遍历
            son = son_dads[son];

        if (son_dads[son] == dad)
            descendants.emplace_back(son);
    }
}
int main()
{
    vector<int> pids = {1, 3, 10, 5};
    vector<int> ppids = {3, 0, 5, 3};
    map<int, int> son_dads;
    build_relation(pids, ppids, son_dads); //构建树结构
    int tokill = 5;
    vector<int> ans;
    getdescendants(son_dads, tokill, ans);
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