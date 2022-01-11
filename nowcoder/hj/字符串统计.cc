#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<sstream>
using namespace std;
int main(){
    string str;
    string strAll,strPart;
    getline(cin, str);
    for(int i=0; i<str.size();i++){
        if(str[i]=='@'){
            strAll=str.substr(0,i);
            strPart=str.substr(i+1);
            break;
        }
    }
    if(strPart.size()==0){
        cout<<strAll;
    }else{
        map<char,int> m;
        vector<char> v;//存储char的顺序
        stringstream ss(strAll);
        string s;
        while(getline(ss,s,',')){
            v.push_back(s[0]);
            m[s[0]]=stoi(s.substr(2));
        }
        ss.clear();
        ss.str(strPart);                //stringstream的复用需要先clear再用str方法，注意str即可set也可get。
        while(getline(ss,s,',')){
            m[s[0]]-=stoi(s.substr(2));
        }
        for(int i=0;i<v.size()-1;i++){
            if(m[v[i]]!=0){
                cout<<v[i]<<":"<<m[v[i]]<<",";
            }
        }
        if(m[v.back()]!=0){
            cout<<v.back()<<":"<<m[v.back()];
        }

    }

    
}

//示例1

// 输入

// a:3,b:5,c:2@a:1,b:2

// 输出

// a:2,b:3,c:2

// 说明

// 全量字符集为3个a，5个b，2个c。

// 已占用字符集为1个a，2个b。如果一个字符被全部占用，不需要输出