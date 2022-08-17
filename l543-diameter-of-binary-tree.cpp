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

// [1,2,3,4,5]
// [1,2,3,4,5,6,7,8]
// [1,2]
// [2,5,null,3,null,1,4]

// brute force
class Solution {
 public:
  vector<vector<TreeNode*>> paths;
  int diameterOfBinaryTree(TreeNode* root) {
    searchPath(vector<TreeNode*>(), root);
    paths.push_back(vector<TreeNode*>{root});
    int maxDepth = 0;
    int deepestPathIndex;
    vector<TreeNode*> deepestPath;
    for (int i = 0; i < paths.size(); i++) {
      auto path = paths[i];
      if (path.size() > maxDepth) {
        maxDepth = path.size();
        deepestPath = path;
        deepestPathIndex = i;
      }
    }
    paths.erase(paths.begin() + deepestPathIndex);
    int diameter = 0;
    for (auto path : paths) {
      int overlap = 1;
      for (int i = 0; i < path.size(); i++) {
        if (deepestPath[i] != path[i]) {
          overlap = i;
          break;
        }
      }
      int distance = deepestPath.size() + path.size() - 2 * overlap;
      diameter = max(distance, diameter);
    }
    return diameter;
  }

  void searchPath(vector<TreeNode*> path, TreeNode* curr) {
    path.push_back(curr);
    if (curr->left || curr->right) {
      if (curr->left) {
        searchPath(path, curr->left);
      }
      if (curr->right) {
        searchPath(path, curr->right);
      }
    } else {
      paths.push_back(path);
    }
  }
};

// recursive solution
class Solution {
 public:
  int diameter = 0;
  int diameterOfBinaryTree(TreeNode* root) {
    diameter = max(search(root) - 1, diameter);
    return diameter;
  }

  int search(TreeNode* root) {
    if (!root) return 0;
    if (!root->left && !root->right) return 1;
    if (root->left && root->right) {
      int depthLeft = search(root->left);
      int depthRight = search(root->right);
      diameter = max(depthLeft + depthRight, diameter);
      return max(depthLeft, depthRight) + 1;
    } else {
      return search(root->left ? root->left : root->right) + 1;
    }
  }
};

// even simpler recursive solution
class Solution {
 public:
  int diameter = 0;
  int diameterOfBinaryTree(TreeNode* root) {
    search(root);
    return diameter;
  }

  int search(TreeNode* root) {
    if (!root) return 0;
    int depthLeft = search(root->left);
    int depthRight = search(root->right);
    diameter = max(depthLeft + depthRight, diameter);
    return max(depthLeft, depthRight) + 1;
  }
};