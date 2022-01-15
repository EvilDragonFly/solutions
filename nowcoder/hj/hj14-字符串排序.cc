#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<string> strs;
    while (n--)
    {
        string str;
        cin >> str;
        strs.emplace_back(str);
    }
    sort(strs.begin(), strs.end());
    for (auto s : strs)
    {
        cout << s << endl;
    }
}