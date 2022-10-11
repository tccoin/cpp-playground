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

class Solution {
 public:
  int minDepth(TreeNode* root) {
    if (!root) return 0;
    queue<TreeNode*> todo;
    todo.push(root);
    TreeNode* curr;
    int depth = 0;
    while (!todo.empty()) {
      depth++;
      size_t layerSize = todo.size();
      for (size_t i = 0; i < layerSize; i++) {
        curr = todo.front();
        todo.pop();
        if (!curr->left && !curr->right) {
          return depth;
        }
        if (curr->left) todo.push(curr->left);
        if (curr->right) todo.push(curr->right);
      }
    }
    return depth;
  }
};