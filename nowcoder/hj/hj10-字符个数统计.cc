#include <iostream>
#include <set>
using namespace std;
int main()
{
    string str;
    cin >> str;
    set<char> s;
    for (auto c : str)
    {
        s.emplace(c);
    }
    cout << s.size();
}