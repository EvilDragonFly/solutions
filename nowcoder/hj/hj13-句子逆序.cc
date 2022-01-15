#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    string str;
    vector<string> strs;
    while (cin >> str)
    {
        strs.emplace_back(str);
    }
    for (int i = strs.size() - 1; i > 0; i--)
    {
        cout << strs[i] << " ";
    }
    cout << strs.front();               // front is a refence,可直接改变vector中值
}