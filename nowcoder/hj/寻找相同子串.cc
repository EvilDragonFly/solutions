#include<iostream>
using namespace std;
int main(){
    string big;
    string small;
    cin>>big>>small;
    int p = big.find(small);
    cout<<p+1;
}