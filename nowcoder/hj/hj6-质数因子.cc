// 2000000014 = 2 * 1000000007
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int num;
    cin >> num;
    for (int i = 2; i < sqrt(num); i++) //每次循环动态调正临界值
    {
        while (num % i == 0) //将对应的质因素全部输出，同时调整num的值
        {
            num /= i;
            printf("%d ", i);
        }
    }
    if (num != 1)
    {
        printf("%d ", num);
    }
}