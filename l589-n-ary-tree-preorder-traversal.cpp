/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

// recursive solution
class Solution
{
public:
    vector<int> ans;
    vector<int> preorder(Node *root)
    {
        search(root);
        return ans;
    }

    void search(Node *current)
    {
        if (!current)
            return;
        ans.push_back(current->val);
        for (auto child : current->children)
        {
            search(child);
        }
    }
};

// iterative solution
class Solution
{
public:
    vector<int> preorder(Node *root)
    {
        vector<int> ans;
        stack<Node *> todo;
        if (root)
            todo.push(root);
        Node *current;
        while (!todo.empty())
        {
            current = todo.top();
            todo.pop();
            ans.push_back(current->val);
            for (auto it = current->children.rbegin(); it != current->children.rend(); it++)
            {
                todo.push(*it);
            }
        }
        return ans;
    }
};