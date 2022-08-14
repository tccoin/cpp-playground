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
    vector<int> postorder(Node *root)
    {
        search(root);
        return ans;
    }

    void search(Node *current)
    {
        if (!current)
            return;
        for (auto child : current->children)
        {
            search(child);
        }
        ans.push_back(current->val);
    }
};

// iterative solution
class Solution
{
public:
    vector<int> ans;
    vector<int> postorder(Node *root)
    {
        stack<Node *> todo;
        todo.push(root);
        Node *current;
        while (!todo.empty())
        {
            current = todo.top();
            todo.pop();
            for (auto child : current->children)
            {
                todo.push(child);
            }
            ans.push_back(current->val);
        }
        return ans;
    }
};