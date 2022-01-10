#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        //贪心算法，先挑选一个最优配合
        //先给一个小孩分配一个饼干，就是部分最优解，注意主题是小孩，不是给饼干分配一个小孩
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int len = s.size();
        int idx = 0; //记录等待分发饼干的编号
        int ret = 0;
        for(auto gi : g){
            while(idx<len&&s[idx]<gi){  //注意前后判断
                idx++;  //跳过不分发
            }
            if (idx<len){
                ret++;
                idx++;  //分发完记得++
            }else{//饼干已经遍历完了
                break;
            }
        }
        return ret;
    }
};