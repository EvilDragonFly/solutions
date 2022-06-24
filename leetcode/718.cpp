#include <iostream>
#include <vector>
using namespace std;
// ##滑动窗口 ##dp

// #二维dp数组
class Solution
{
public:
    int findLength(vector<int> &nums1, vector<int> &nums2)
    {
        int ret(0);
        int m = nums1.size() + 1;
        int n = nums2.size() + 1;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (nums1[i - 1] == nums2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    ret = ret > dp[i][j] ? ret : dp[i][j];
                }
            }
        }
        return ret;
    }
};

// #一维dp数组
class Solution1
{
public:
    int findLength(vector<int> &A, vector<int> &B)
    {
        vector<int> dp(vector<int>(B.size() + 1, 0));
        int ret = 0;
        for (int i = 1; i <= A.size(); i++)
        {
            for (int j = B.size(); j > 0; j--)
            {
                if (A[i - 1] == B[j - 1])
                {
                    dp[j] = dp[j - 1] + 1;
                    ret = ret>dp[j]?ret:dp[j];
                }
            }
        }
        return ret;
    }
};

// #滑动窗口
class Solution2 {
public:
    int maxLength(vector<int>& A, vector<int>& B, int addA, int addB, int len) {
        int ret = 0, k = 0;
        for (int i = 0; i < len; i++) {
            if (A[addA + i] == B[addB + i]) {
                k++;
            } else {
                k = 0;
            }
            ret = max(ret, k);
        }
        return ret;
    }
    int findLength(vector<int>& A, vector<int>& B) {
        int n = A.size(), m = B.size();
        int ret = 0;
        for (int i = 0; i < n; i++) {
            int len = min(m, n - i);
            int maxlen = maxLength(A, B, i, 0, len);    // 固定B
            ret = max(ret, maxlen);
        }
        for (int i = 0; i < m; i++) {
            int len = min(n, m - i);
            int maxlen = maxLength(A, B, 0, i, len);    // 固定A
            ret = max(ret, maxlen);
        }
        return ret;
    }
};
