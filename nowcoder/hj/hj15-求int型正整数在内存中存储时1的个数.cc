// 解题三种方式，一种取余，一种位运算，一种用__builtin_popcount(x)
#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int ret(0);
    for (int i = 0; i < 32; i++)
    {
        if ((n >> i) % 2 == 1) // check最后一位是不是1
            ret++;
    }
    cout << ret;
}
// #include <stdio.h>
// int main(void)
// {
// 	int num;
// 	int count = 0;
// 	#pragma warning(suppress : 4996)//用VS写的，需要压制警告
// 	scanf("%d", &num);
// 	int length = sizeof(int) * 8;
// 	for (int i = 0; i < length - 1; i++)
// 	{
// 		if (num & 1)
// 			count++;
// 		num >>= 1;
// 	}
// 	printf("%d\r\n", count);
// 	return 0;
// }

#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    cout << __builtin_popcount(n);
}
// https://www.geeksforgeeks.org/builtin-functions-gcc-compiler/