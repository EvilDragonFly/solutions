
#include <bits/stdc++.h>
using namespace std;
class LogSystem {

public:
    LogSystem()
    {}

    void Add(int id, int timeStamp)
    {
        log[id] = timeStamp;
        tStamps[timeStamp]++;
    }

    int Delete(int id)
    {
        if (!log.count(id)) {
            return -1;
        }
        int timeStamp = log[id];
        log.erase(id);
        tStamps[timeStamp]--;
        if (tStamps[timeStamp] == 0) {
            tStamps.erase(timeStamp);
        }
        return 0;
    }

    int Query(int startTime, int endTime)
    {
        int ret(0);
        for (int i = startTime; i <= endTime; i++) {
            if (tStamps.count(i)) {
                ret += tStamps[i];
            }
        }
        return ret;
    }

private:
    unordered_map<int, int> log;      // 记录id与timestamp
    unordered_map<int, int> tStamps;  // 记录时间戳个数
};
int main()
{
    LogSystem ls;
    ls.Add(1, 5);
    ls.Add(2, 5);
    ls.Add(3, 6);
    cout << ls.Query(5, 6) << endl;
    ls.Delete(2);
    ls.Delete(4);
    cout << ls.Query(5, 6);
}

// 输入：
// ["LogSystem","add","add","add","query","delete","delete","query"]
// [[],[1,5],[2,5],[3,6],[5,6],[2],[4],[5,6]]
// 输出：
// [null,null,null,null,3,0,-1,2]
// 解释：
// 第一个操作是初始化，没有返回值；
// 前三个 Add 操作加入了 ID 为 1、2、3 的日志，timeStamp 分别为 5、5、6；
// 第一次 Query 操作查询 timeStamp 范围为[5,6]的日志数量，返回 3；
// 第一次 Delete 操作删除了 ID 为 2 的日志，删除成功，返回 0；
// 第二次 Delete 操作试图删除 ID 为 4 的日志，没有该日志，操作失败，返回 -1；
// 最后一次 Query 操作查询 timeStamp 范围为[5,6]的日志数量，由于该范围中已经有一条日志被删除了，故返回 2。
// 注：输出中的 null 表示此对应函数无输出（等同于 C 语言的 void 类型）。