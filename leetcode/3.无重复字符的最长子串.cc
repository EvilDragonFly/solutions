#include <iostream>
#include <string>
#include <set>
#include <deque>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        deque<char> dq;
        int ans(0);
        for (auto c : s)
        {
            deque<char>::iterator it = find(dq.begin(), dq.end(), c);
            if (it == dq.end())
            {
                dq.emplace_back(c);
            }
            else
            {
                dq.erase(dq.begin(), it + 1);//删除指定range元素
                dq.emplace_back(c);
            }
            ans = ans > dq.size() ? ans : dq.size();
        }
        return ans;
    }
};

int main(){
    string str ="pwwkew";
    Solution s;
    cout<<s.lengthOfLongestSubstring(str);
}

// 滑动窗口，也可用数组char[256]记录字符串最近出现index，遇到相同元素，相减就可得到子串长度
// 或者用map<char,bool>或者set记录子串是否包含对应的char，同时记录子串的start，end，遇到已存在的char更新map，start，end
// 链表结构，高效增删元素，且保持元素相对顺序
// 链表不需要记录start,end