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

// recursive solution
class Solution
{
public:
    vector<int> ans;
    vector<int> preorderTraversal(TreeNode *root)
    {
        search(root);
        return ans;
    }

    void search(TreeNode *current)
    {
        if (!current)
            return;
        ans.push_back(current->val);
        search(current->left);
        search(current->right);
    }
};

// iterative solution
class Solution
{
public:
    vector<int> ans;
    vector<int> preorderTraversal(TreeNode *root)
    {
        stack<TreeNode *> todo;
        if (root)
            todo.push(root);
        TreeNode *current;
        while (!todo.empty())
        {
            current = todo.top();
            todo.pop();
            ans.push_back(current->val);
            if (current->right)
                todo.push(current->right);
            if (current->left)
                todo.push(current->left);
        }
        return ans;
    }
};