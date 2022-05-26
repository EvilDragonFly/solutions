#include <iostream>
#include <vector>
using namespace std;
// Author: Huahua
// Running time: 19 ms (<98.70%)
class Solution
{
public:
    bool canIWin(int M, int T)
    {
        const int sum = M * (M + 1) / 2;
        if (sum < T)
            return false;
        if (T <= 0)
            return true;
        m_ = vector<char>(1 << M, 0);
        return canIWin(M, T, 0);
    }

private:
    vector<char> m_; // 0: unknown, 1: won, -1: lost, not for the player1 but the current player
    bool canIWin(int M, int T, int state)
    {
        // if (T <= 0)
        //     return false;
        if (m_[state])
            return m_[state] == 1;
        for (int i = 0; i < M; ++i)
        {
            if (state & (1 << i))
                continue; // number i used
            // The next player can not win, current player wins
            if (i + 1 >= T || !canIWin(M, T - (i + 1), state | (1 << i)))
                return m_[state] = 1; // store the state that the current player can win
        }
        // Current player loses.
        m_[state] = -1;
        return false;
    }
};
int main()
{
}
//难点1.构造state通过二进制位表示数字选取状态
//难点2.dp数组m_来保存各状态下当前player的输赢情况