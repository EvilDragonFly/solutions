/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{
public:
    bool isSubtree(TreeNode *root, TreeNode *subRoot)
    {
        if (subRoot == nullptr)
            return true;
        //子树不存在的情况需要结束,防止获取左右子树空指针
        if (root == nullptr)
            return false;
        //递归父树，查找满足条件的节点
        return isEqual(root, subRoot) || isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
    //递归判断是否相等
    bool isEqual(TreeNode *t1, TreeNode *t2)
    {
        //都为空指针，或者都不为空指针且满足各部分相等
        return t1 == nullptr && t2 == nullptr || t1 && t2 && t1->val == t2->val && isEqual(t1->left, t2->left) && isEqual(t1->right, t2->right);
    }
};