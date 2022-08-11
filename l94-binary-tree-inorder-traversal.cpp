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

// immutable recusive solution
class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        if (!root)
            return vector<int>();
        vector<int> left = inorderTraversal(root->left);
        vector<int> right = inorderTraversal(root->right);
        vector<int> ans(left);
        ans.push_back(root->val);
        ans.insert(ans.end(), right.begin(), right.end());
        return ans;
    }
};

// iterative solution
class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        stack<TreeNode *> todo;
        TreeNode *current = root;
        while (current || !todo.empty())
        {
            if (current)
            {
                todo.push(current);
                current = current->left;
            }
            else
            {
                current = todo.top();
                todo.pop();
                ans.push_back(current->val);
                current = current->right;
            }
        }
        return ans;
    }
};