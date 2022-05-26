#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;
// Definition for a Node.
class Node
{
public:
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution
{
public:
    Node *cloneGraph(Node *node)
    {
        if (node == nullptr)
            return nullptr;
        collectOrigin(node);
        // clone all the nodes
        for (auto n : oset)
        {
            Node *newn = new Node(n->val);
            nmap[newn->val] = newn;
        }
        // build the graph
        for (auto node : oset)
        {
            Node *nnode = nmap[node->val];
            auto neighbors = node->neighbors;
            for (auto n : neighbors)
                nnode->neighbors.push_back(nmap[n->val]);
        }
        return nmap[node->val];
    }

    void collectOrigin(Node *node)
    {
        // collect origin nodes
        if (oset.count(node))
            return;
        oset.emplace(node);
        for (auto n : node->neighbors)
            collectOrigin(n);
    }

private:
    unordered_set<Node *> oset;      // recorded origin graph nodes
    unordered_map<int, Node *> nmap; // recorded new graph nodes
};

class Solution1
{
    unordered_map<Node *, Node *> myMap;

public:
    Node *cloneGraph(Node *node)
    {
        if (!node)
            return NULL;
        if (myMap.count(node))
        {
            Node *newNode = new Node(node->val);
            myMap[node] = newNode;
            for (auto n:node->neighbors)
            {
                newNode->neighbors.push_back(cloneGraph(n));
            }
            return newNode;
        }
        else
        {
            return myMap[node];
        }
    }
};