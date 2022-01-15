#include <string>
#include <iostream>
using namespace std;
int main()
{
    string str;
    while (cin >> str)
    {
        while (1)
        { //处理每一行字符串
            int len = str.length();
            if (len <= 8)
            {
                cout << str + string(8 - len, '0') << endl;
                break;
            }
            else
            {
                string s = str.substr(0, 8);
                str = str.substr(8);
                cout << s << endl;
            }
        }
    }
}
// string(int ,char)构造方法