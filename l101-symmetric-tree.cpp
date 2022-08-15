/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

// recursive solution
class Solution {
 public:
  bool isSymmetric(TreeNode* root) { return compare(root->left, root->right); }

  bool compare(TreeNode* left, TreeNode* right) {
    if (!left && !right)
      return true;
    else if (!left || !right)
      return false;
    if (left->val != right->val) return false;
    return compare(left->right, right->left) &&
           compare(left->left, right->right);
  }
};

// iterative solution
class Solution {
 public:
  bool isSymmetric(TreeNode* root) {
    queue<TreeNode*> todoLeft, todoRight;
    TreeNode *left, *right;
    todoLeft.push(root->left);
    todoRight.push(root->right);
    while (!todoLeft.empty() && !todoRight.empty()) {
      left = todoLeft.front();
      right = todoRight.front();
      todoLeft.pop();
      todoRight.pop();
      if (!left && right || left && !right) {
        return false;
      } else if (left && right) {
        if (left->val != right->val) {
          return false;
        } else {
          todoLeft.push(left->left);
          todoRight.push(right->right);
          todoLeft.push(left->right);
          todoRight.push(right->left);
        }
      }
    }
    return todoLeft.empty() && todoRight.empty();
  }
};