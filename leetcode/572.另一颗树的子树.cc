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
        deque<TreeNode *> nodes{root};
        while (!nodes.empty())
        {
            for (auto node : nodes)
            {
                if (isEqual(node, subRoot))
                    return true;
            }
            // bfs
            int len = nodes.size();
            for (int i = 0; i < len; i++)
            {
                auto node = nodes.front();
                if (node->left != nullptr)
                    nodes.emplace_back(node->left);
                if (node->right != nullptr)
                    nodes.emplace_back(node->right);
                nodes.pop_front();
            }
        }
        return false;
    }
    //递归判断是否相等
    bool isEqual(TreeNode *t1, TreeNode *t2)
    {
        //存在空指针的情况
        if (t1 == nullptr && t2 == nullptr)
            return true;
        else if (t1 == nullptr || t2 == nullptr)
            return false;
        //判断节点是否相等
        else if (t1->val != t2->val)
            return false;
        else if (!isEqual(t1->left, t2->left) || !isEqual(t1->right, t2->right))
            return false;
        return true;
    }
};