#include <iostream>
#include <string>
#include <cctype>
#include<sstream>
using namespace std;
int main()
{
    string str;
    int x(0), y(0);
    getline(cin, str);
    stringstream ss(str);
    while (getline(ss, str, ';'))               //输入流使用cin的话测试会一直阻塞，使用stringstream可以获取EOF位置从而跳出循环; 如果是cin按ctlz再回车
    {
        if (str.size() <= 0)
            continue;
        char d = str[0];
        if (d != 'A' && d != 'D' && d != 'S' && d != 'W')
            continue;
        string num = str.substr(1);
        int len;
        for (auto c: num)
        {
            if (!isdigit(c))
                goto label;
        }
        len = stoi(num);
        switch (d)
        {
        case 'A':
            x -= len;
            break;
        case 'D':
            x += len;
            break;
        case 'W':
            y += len;
            break;
        case 'S':
            y -= len;
        }
    label:
        continue;
    }
    cout << x << "," << y;
}



// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(0),cout.tie(0);
//     string s,t;
//     while(getline(cin,s)) {
//         stringstream ss(s);
//         pair<int,int> p(0,0);
//         while(getline(ss,t,';')) {
//             if(t.empty())
//                 continue;
//             string _ = t.substr(1);
//             if(regex_match(_,regex("[0-9]*"))) {         //采用正则表达式
//                 switch(t[0]) {
//                     case 'A': p.first -= stoi(_); break; //左移
//                     case 'D': p.first += stoi(_); break; //右移
//                     case 'W': p.second += stoi(_); break; //上移
//                     case 'S': p.second -= stoi(_); break; //下移
//                     default: break; //无效
//                 }           
//             }
//         }
//         cout << p.first << "," << p.second << endl;
//     }
//     return 0;
// }