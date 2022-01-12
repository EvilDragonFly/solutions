#include <iostream>
#include <string>
using namespace std;
//相当于9进制转10进制
//(1<=N<=888888888)，由于数字在int的方位内，可直接暴力解决
int main()
{
    string num;
    cin >> num;
    int ret(0);
    for (int i = num.size() - 1, power = 1; i >= 0; i--, power *= 9)
    {
        int n = num[i] - '0';
        if (n > 4)
            n--;
        ret += n * power;
    }
    cout << ret;
}