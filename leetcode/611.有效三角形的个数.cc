#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        //首先处理异常状态
        if (nums.size()<3){
            return 0;
        }
        //贪心算法，一步一步算个数
        //先排序，减少循环次数，防止超时
        sort(nums.begin(),nums.end());
        int ret = 0;
        int len = nums.size();
        //固定最长边i
        for(int i=len-1; i>=2; i--){
            int left = 0, right = i-1;
            while(left<right){
                if (nums[left]+nums[right]>nums[i]){
                    // caculate nums
                    ret += right-left;
                    right--;        //更换right的范围
                }else{
                    left++;         //确定left能满足的零界点
                }
            }
           
        }
           
        
        return ret;
    }
};