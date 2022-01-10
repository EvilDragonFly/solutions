#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    string addBinary(string a, string b) {
        int up = 0;    //标记向前进位的值
        string longer = a.size()>b.size() ? a:b;
        string shorter;
        if (longer == b) {
            shorter = a;
        } else {
            shorter = b;
        }
        int len = longer.size();
        int offset = len-shorter.size();
        shorter = string(offset, '0') + shorter;
        //stringstream s("");
        for (int i=len-1;i>=0;i--){
            int sum = longer[i]-'0'+shorter[i]-'0'+up;
            // 需要进位
            if (sum>1){
                up = 1;
                sum = sum -2;
            }else{
                up = 0;
            }
            longer[i] = sum+'0';
        }
        if (up>0){
            longer = string(1,'1') + longer;
        }
        return longer;


    }
};
// 关键点，string的构造函数, char与int的相互转换
// https://www.delftstack.com/howto/c/convert-int-to-char/