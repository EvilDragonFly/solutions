
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> partitionLabels(string s) {
        //贪心算法，一步一步求部分最优解,每次确定一组
        //遍历字符串，如果访问当之前出现的字符串，就直接归为一组。
        map<char,int> m;
        for (int i=0; i< s.size(); i++){
            m[s[i]] = i;
        }
        vector<int> ans;
        int start = 0;  //记录每一组的第一个字母的位置
        int end = 0; //记录每一组最后一个字母的位置
        for (int i=0;i<s.size();i++){            
            end = max (end, m[s[i]]);   //根据遍历到的字母实时更新end
            if (i==end){     //满足条件
                ans.push_back(end - start +1);
                start = end +1;
            }
            
        }
        return ans;

    }
};