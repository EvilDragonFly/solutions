#include<iostream>
#include<string>
using namespace std;
int main(){
    string str;
    getline(cin, str);
    char target = tolower(getchar());
    int ret(0);
    for(auto c : str){
        if (tolower(c) == target)
            ret++;
    }
    cout<<ret;
}