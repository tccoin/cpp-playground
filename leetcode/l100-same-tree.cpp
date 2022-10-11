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
  bool isSameTree(TreeNode* p, TreeNode* q) {
    queue<pair<TreeNode*, TreeNode*> > todo;
    todo.push(make_pair(p, q));
    while (!todo.empty()) {
      auto left = todo.front().first;
      auto right = todo.front().second;
      todo.pop();
      if (left == NULL && right == NULL) {
        continue;
      } else if (left == NULL || right == NULL || left->val != right->val) {
        return false;
      } else {
        todo.push(make_pair(left->left, right->left));
        todo.push(make_pair(left->right, right->right));
      }
    }
    return true;
  }
};