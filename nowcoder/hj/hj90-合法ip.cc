#include<iostream>
#include<sstream>
using namespace std;
// int main(){
//     string ip;
//     while(cin>>ip){
//         unsigned int n1,n2,n3,n4;
//         char dot1,dot2,dot3;
//         stringstream ss;
//         ss<<ip;
//         ss>>n1>>dot1>>n2>>dot2>>n3>>dot3>>n4;                                   //stringstream可以根据字符串和要传递的类型自动分段
//         cout<<n1<<" "<<n2<<" "<<n3<<" "<<n4<<endl; 
//         if(n1>=0&&n1<=255 && n2>=0&&n2<=255 &&  n3>=0&&n3<=255 && n4>=0&&n4<=255){
//             cout<<"YES"<<endl;
//         }else{
//             cout<<"NO"<<endl;
//         }
        
//     }

// }
int main(){
    string ip;
    while(cin>>ip){
        int count(0);    //记录数字个数
        bool isValid = true;
        for(int i=0;i<ip.size();i++){
            string num;
            while(ip[i]!='.'&&i<ip.size()){
                num+=ip[i];
                i++;
            }
            count++;
            if(num.size()==0){
                isValid = false;
                break;
            }
            // stringstream ss;
            // ss<<num;
            // int n;
            // ss>>n;
            int n = stoi(num);
            if(n!=0&&num[0]=='0' || num[0]=='+' || n<0 || n>255){
                isValid = false;
                break;
            }
            
        }
        if(count!=4){
            isValid = false;
        }
        if(isValid){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
        
    }

}