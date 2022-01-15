#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main()
{
    string str;
    int x(0), y(0);
    while (getline(cin, str, ';'))
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