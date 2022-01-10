//nc34 求路径
// 注意点，防止溢出，注意/运算可能导致取整后误差

#include <iostream>
int uniquePaths(int,int);
int main()
{
    std::cout<<uniquePaths(59,5);
}
int uniquePaths(int m, int n)
{
    // 一共要往下移动m-1次，往左移动n-1次相当于在m+n-1个bit中找到m-1个bit置1，其余的置0
    long long ret = 1;      //防止溢出
    if (m == 1 || n == 1)
    {
        return ret;
    }
    for (int x = 1, y=n; x <= m - 1; x++, y++)
    {
        ret = ret*y/x;          //注意不能用点乘，否则取整会导致错误结果,且必须采用这种分子分母都为递增的形式，否者/会出现取整误差
        std::cout<<"ret:"<<ret<<std::endl;
    }
    return ret;
}