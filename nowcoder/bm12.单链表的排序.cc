#include <vector>
#include <algorithm>
using namespace std;
struct ListNode
{
    int val;
    struct ListNode *next;
};

class Solution
{
public:
    /**
     *
     * @param head ListNode类 the head node
     * @return ListNode类
     */
    ListNode *sortInList(ListNode *head)
    {
        // write code here
        vector<ListNode *> nodes;
        while (head != nullptr)
        {
            nodes.emplace_back(head);
            head = head->next;
        }
        sort(nodes.begin(), nodes.end(), [](ListNode *node1, ListNode *node2)
             { return node1->val < node2->val; });
        for (int i = 0; i < nodes.size() - 1; i++)
        {
            nodes[i]->next = nodes[i + 1];
        }
        nodes.back()->next = nullptr; //防止出现环路
        return nodes[0];
    }
};