#include <iostream>
#include <string>
using namespace std;
struct TreeNod
{
    char val;
    TreeNod *left;
    TreeNod *right;
    TreeNod(char v)
    {
        val = v;
        right = left = nullptr;
    }
    TreeNod(char v, TreeNod *l, TreeNod *r)
    {
        val = v;
        left = l;
        right = r;
    }
};
void constructTree(TreeNod *father, string str)
{
    int len = str.size();
    int mid(len); // mid作为分割str中作为左右子树的标记，如果有右子树，则str[mid]==','，否者mid==len
    for (int i = 0, count = 0; i < len; i++)
    {
        if (str[i] == '{')
            count++;
        else if (str[i] == '}')
            count--;
        else if (str[i] == ',' && count == 0)
        {
            mid = i;
            break;
        }
    }
    //左子树
    if (mid != 0)
    {
        TreeNod *left = new TreeNod(str[0]);
        father->left = left;
        //有子树
        if (str[1] == '{')
            constructTree(left, str.substr(2, mid - 3));
    }
    //右子树
    if (mid != len)
    {
        TreeNod *right = new TreeNod(str[mid + 1]);
        father->right = right;
        //有子树
        if (str[mid + 2] == '{')            //这里字符数组越界不会出错，如果是赋值操作会报错
            constructTree(right, str.substr(mid + 3, len - mid - 4));
    }
}
void printStr(TreeNod *head)
{
    if (head->left != nullptr)
    {
        printStr(head->left);
    }
    cout << head->val;
    if (head->right != nullptr)
    {
        printStr(head->right);
    }
}
int main()
{
    // string str;
    // getline(cin,str);
    string str = "a{b{d,e{g,h{,i}}},c{f}}";
    //建立树结构
    if (str.empty())
    {
        return 0;
    }
    int len = str.size();
    TreeNod head(str[0]);
    if (str.size() > 1)
        constructTree(&head, str.substr(2, len - 3));
    printStr(&head);
    // 考虑delete堆中数据
    return 0;
}
