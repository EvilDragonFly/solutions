#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str;
    while (getline(cin, str))
    {
        int count(0);
        for (auto c : str)
        {
            if (c >= 'A' && c <= 'Z')
                count++;
        }
        cout << count << endl;
    }
}