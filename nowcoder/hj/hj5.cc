#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str;
    while (cin >> str)
    {
        int n;
        // int n = stoi(str); //stoi(str,nullptr,0) //自动根据前面输入的0x判断是16进制,base不赋值的话，默认是10进制
        sscanf(str.substr(2).c_str(), "%x", &n); //了解sscanf,scanf,sprinf相关输入输出的io方法
        cout << n << endl;

        // string str;
        // while (cin >> str)
        // {
        //     cout << stoi(str, 0, 16) << endl;
        // }
    }
}