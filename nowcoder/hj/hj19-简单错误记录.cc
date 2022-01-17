#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;
int main()
{
    vector<pair<string, pair<int, int>>> logs; // errorname, rownum, count
    string log;
    while (getline(cin, log))
    {
        string path, num;
        stringstream ss(log); // 已知个数分段
        ss >> path >> num;
        string file = path.substr(path.find_last_of('\\') + 1); //如果没有/,直接就是名字
        string errname;
        if (file.size() > 16)
            errname = file.substr(file.size() - 16);
        else
            errname = file;
        int rownum = stoi(num);
        bool NeedPush = true; //判断是否存在同名的记录,需要变更日志
        for (auto &p : logs)
        {
            if (p.first == errname && p.second.first == rownum) // "相同"的处理
            {
                NeedPush = false;
                p.second.second++;
                break;
            }
        }
        if (NeedPush)
            logs.push_back(make_pair(errname, make_pair(rownum, 1)));
    }
    int start(0); //只输出最后记录的8个记录
    int len = logs.size();
    if (len > 8)
        start = len - 8;
    for (int i = start; i < len; i++)
    {
        cout << logs[i].first << " " << logs[i].second.first << " " << logs[i].second.second << endl;
    }
}
// 解决方案:
// 1.同名且行数相等对应记录个数值加1，注意这不会增加需要记录的日志数}
// 2.无同名或者同名行数不一致直接push_back,
// 3.最后直接输出记录列表中的最后8个数据
//注意，不能用deque来保持队列长度为8个，否则后面遇到的数据如果之前出现过但没有被列表记录，就会被错误地记录