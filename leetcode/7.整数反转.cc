#include<cmath>
#include<climits>
#include<stack>
using namespace std;
class Solution {
public:
    int reverse(int x) {
        long long mx(0);
        bool isNegative = x<0;
        if(isNegative)  mx-=x;
        else mx=x;
        stack<int> st;
        while(mx>0){
            st.emplace(mx%10);
            mx/=10;
        }
        long long ans(0);
        for(int power=0;!st.empty();power++){
            int num = st.top();
            ans+=pow(10,power)*num;
            st.pop();
        }
        if(isNegative) ans=-ans;
        if(ans<INT_MIN||ans>INT_MAX)
            return 0;
        return ans;
        

    }
};

class Solution {
public:
    int reverse(int x) {
        long ans(0);
        while(x){
            ans=ans*10+x%10;
            x/=10;
        }
        if(ans<INT_MIN||ans>INT_MAX) return 0;
        return ans;      

    }
};