#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
using namespace std;
int main(){
    int num;     //候选人人数
    cin>>num;
    vector<char> candidates;
    set<char> s;
    while(num--){
        char c;
        cin>>c;
        s.insert(c);
        candidates.push_back(c);
        cout<<c<<endl;
    }
    int n;
    cin>>n;
    map<char,int> m;            //记录票数
    m['0']=0;   //invaild票数
    while(n--){
        string str;
        cin>>str;
        if( str.size()>1 || s.find(str[0])==s.end() ){
            m['0']++;
        }else{
            m[str[0]]++;
        }
    }
    for(auto c : candidates){
        cout<<c<<" : "<<m[c]<<endl;
    }
    cout<<"Invalid : "<<m['0']<<endl;
}