#include<iostream>
#include<vector>
using namespace std;
struct ListNode{
    int val;
    ListNode *next;
    ListNode(){
        val=0;
        next=nullptr;
    }
    ListNode(int n){
        val=n;
        next=nullptr;
    }
    ListNode(int n, ListNode*nex){
        val = n;
        next=nex;
    }
};
int main(){
    int count,headval;
    cin>>count>>headval;
    ListNode *head = new ListNode(headval);
    ListNode *node = head;
    count--;
    while(count--){
        int before,after;
        cin>>after>>before;
        node = head;
        while(node->val!=after&&node->val!=before){
            node = node->next;
        }
        if(node->val==after){    //需要在node前插入before
            ListNode *tmp=head;
            while(tmp->next->val!=after){
                tmp = tmp->next;
            }
            tmp->next=new ListNode(before,node);
        }
        else{
            node->next=new ListNode(after,node->next);
        }
    }
    int target;
    cin>>target;
    vector<int>ret;
    while(head!=nullptr){
        if(head->val!=target)
            ret.emplace_back(head->val);
        head = head->next;
    }
    for(auto n:ret){
        cout<<n<<" ";
    }
}