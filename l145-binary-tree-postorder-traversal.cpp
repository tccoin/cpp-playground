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
    vector<int> result;
    vector<int> postorderTraversal(TreeNode *root)
    {
        search(root);
        return result;
    }

    void search(TreeNode *root)
    {
        if (!root)
        {
            return;
        }
        search(root->left);
        search(root->right);
        result.push_back(root->val);
    }
};

// iterative solution (reverse preorder traversal)
class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> result;
        stack<TreeNode *> todo;
        todo.push(root);
        TreeNode *current;
        while (!todo.empty())
        {
            current = todo.top();
            todo.pop();
            if (!current)
                break;
            result.push_back(current->val);
            if (current->left)
                todo.push(current->left);
            if (current->right)
                todo.push(current->right);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};