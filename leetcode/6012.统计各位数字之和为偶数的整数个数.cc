#include<iostream>
using namespace std;
class Solution {
public:
    int countEven(int num) {                //0~9结尾奇数偶数个数一致
        int low = num%10;//个位数
        int tmp = num/10;
        int other(0);//除个位数，其他数字之和
        while(tmp>0){            
            other+=tmp%10;
            tmp/=10;
        }
        if(other%2==0){
            return (num-low)/2+low/2;
        }else{
            return (num-low)/2-1+(low+1)/2;
        }        
        
        
    }
};
int main(){
    Solution s;
    cout<<s.countEven(30);
}