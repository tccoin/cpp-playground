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
  TreeNode* sortedArrayToBST(vector<int>& nums) {
    return constructNode(nums, 0, nums.size() - 1);
  }
  TreeNode* constructNode(vector<int>& nums, int left, int right) {
    if (left > right) return nullptr;
    if (left == right) return new TreeNode(nums[left]);
    int center = left + (right - left) / 2;
    TreeNode* leftNode = constructNode(nums, left, center - 1);
    TreeNode* rightNode = constructNode(nums, center + 1, right);
    return new TreeNode(nums[center], leftNode, rightNode);
  }
};