#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    int maxDepth(string s) {
        // 注意str中括号是成对出现的，不能从两边来看
        int ret = 0;
        int add = 0; //标记未配对的(
        for (auto c : s){          
            if (c=='('){
                add++;
            }
            if (c==')'){
                add--;
            }
            ret = max(ret,add);
        }
        return ret;
    }
    // c++11 的for循环
    // max函数
    //所求就是遍历过程中出现的一次最大没有配对'('的个数,也就是add的最大值
};