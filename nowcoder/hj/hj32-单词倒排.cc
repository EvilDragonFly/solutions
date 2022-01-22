#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;
int main()
{
    string str;
    getline(cin, str);
    string s;
    vector<string> ret;
    for (int i = 0; i < str.size(); i++)
    {
        if (isalpha(str[i]))                    // isalpha,isalnum,isdigit
            s += str[i];
        else if (!s.empty())
        {
            ret.emplace_back(s);
            s = "";
        }
    }
    if (!s.empty())
        ret.emplace_back(s);
    reverse(ret.begin(), ret.end());
    for (auto s : ret)
    {
        cout << s << " ";
    }
}