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

// recursive
class Solution {
 public:
  vector<TreeNode*> path;
  vector<int> search(TreeNode* node) {
    if (!node) return {0, 0};
    vector<int> resultLeft = search(node->left);
    vector<int> resultRight = search(node->right);
    int rob = node->val + resultLeft[1] + resultRight[1];
    int notrob =
        max(resultLeft[0], resultLeft[1]) + max(resultRight[0], resultRight[1]);
    return {rob, notrob};
  }
  int rob(TreeNode* root) {
    vector<int> result = search(root);
    return max(result[0], result[1]);
  }
};

// DP
class Solution {
 public:
  int rob(TreeNode* root) {
    struct Node {
      int val;
      vector<int> children;
      Node(int val_) : val(val_) {}
    };
    vector<Node> nodes;
    queue<pair<TreeNode*, int>> todo;
    todo.push({root, -1});
    TreeNode* curr;
    int parentIndex;
    int currIndex;
    while (!todo.empty()) {
      curr = todo.front().first;
      parentIndex = todo.front().second;
      todo.pop();
      currIndex = nodes.size();
      nodes.emplace_back(curr->val);
      if (parentIndex >= 0) {
        nodes[parentIndex].children.push_back(currIndex);
      }
      if (curr->left) todo.push({curr->left, currIndex});
      if (curr->right) todo.push({curr->right, currIndex});
    }
    vector<int> rob(nodes.size(), 0);
    vector<int> notRob(nodes.size(), 0);
    for (int i = nodes.size() - 1; i > -1; i--) {
      if (nodes[i].children.size() == 0) {
        rob[i] = nodes[i].val;
        notRob[i] = 0;
      } else {
        rob[i] = nodes[i].val;
        for (int j : nodes[i].children) {
          rob[i] += notRob[j];
          notRob[i] += max(notRob[j], rob[j]);
        }
      }
    }
    return max(rob[0], notRob[0]);
  }
};