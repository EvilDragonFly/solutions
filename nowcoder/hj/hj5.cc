#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str;
    while (cin >> str)
    {
        int n;
        sscanf(str.substr(2).c_str(), "%x", &n); //了解sscanf,scanf,sprinf相关输入输出的io方法
        cout << n << endl;

        // string str;
        // while (cin >> str)
        // {
        //     cout << stoi(str, 0, 16) << endl;
        // }
    }
}