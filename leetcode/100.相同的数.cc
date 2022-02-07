
// Definition for a binary tree node.
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
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (p == nullptr && q == nullptr) //注意防止空指针异常
            return true;
        if ((p == nullptr) != (q == nullptr) || p->val != q->val) //只有一个为空指针，则返回false
            return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};