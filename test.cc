#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a = 10;
    int &b = a;
    a = 20;
    cout<<b<<endl;
    int c = 40;
    b = c;
    c = 50;
    cout<<"a:"<<a<<"b:"<<b<<"c:"<<c<<endl;
}