#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    string convertToBase7(int num) {
        string ret = "";
        if (num<0){
            ret += "-";
            num = - num;
        }
        if (num<7){
            ret += to_string(num);
            return ret;
        }
        vector<int> bits;  //记录7进制数字位
        int left = 0;     //余数
        while(1){
            left = num%7;
            bits.push_back(left);
            num = num/7;
            if (num<7){
                bits.push_back(num);
                break;
            }

        }
        while(bits.size()!=0){
            ret += to_string(bits.back());
            bits.pop_back();
        }
        return ret;
    }
};
int main(){
    Solution s;
    cout<< s.convertToBase7(100);
}
// g++ -std=c++11
// gcc -lstdc++