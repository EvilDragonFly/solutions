#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int x, y, z;
    while (cin >> x >> y >> z)
    {

        vector<vector<int>> A(x, vector<int>(y));               // vector的构造方法
        vector<vector<int>> B(y, vector<int>(z));
        for (int i = 0; i < x; i++)
        {
            vector<int> nums(y);
            for (auto &n : nums)
                cin >> n;
            A[i] = nums;
        }
        for (int i = 0; i < y; i++)
        {
            vector<int> nums(z);
            for (auto &n : nums)
                cin >> n;
            B[i] = nums;
        }
        vector<vector<int>> ret(x, vector<int>(z));
        for (int i = 0; i < x; i++)
            for (int j = 0; j < z; j++)
            {
                int sum(0);
                for (int k = 0; k < y; k++)
                    sum += A[i][k] * B[k][j];
                ret[i][j] = sum;
            }
        for (auto v : ret)
        {
            for (auto n : v)
            {
                cout << n << " ";
            }
            cout << endl;
        }
    }
}