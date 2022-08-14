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

// DFS iterative
class Solution {
 public:
  typedef pair<int, TreeNode*> NodePair;
  int maxDepth(TreeNode* root) {
    stack<NodePair> todo;
    if (root) todo.push(NodePair(1, root));
    int maxDepth = 0;
    TreeNode* current;
    while (!todo.empty()) {
      int depth = todo.top().first;
      current = todo.top().second;
      todo.pop();
      if (depth > maxDepth) maxDepth = depth;
      if (current->right) todo.push(NodePair(depth + 1, current->right));
      if (current->left) todo.push(NodePair(depth + 1, current->left));
    }
    return maxDepth;
  }
};

// BFS iterative
class Solution {
 public:
  int maxDepth(TreeNode* root) {
    queue<TreeNode*> todo;
    if (root) todo.push(root);
    int maxDepth = 0;
    TreeNode* current;
    while (!todo.empty()) {
      size_t currentLayerSize = todo.size();
      for (size_t i = 0; i < currentLayerSize; i++) {
        current = todo.front();
        todo.pop();
        if (current->left) todo.push(current->left);
        if (current->right) todo.push(current->right);
      }
      maxDepth++;
    }
    return maxDepth;
  }
};

// DFS recursive
class Solution {
 public:
  int maxDepth(TreeNode* root) {
    return root ? max(maxDepth(root->left), maxDepth(root->right)) + 1 : 0;
  }
};