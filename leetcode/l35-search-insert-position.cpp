class Solution {
 public:
  int searchInsert(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1, center;
    while (left <= right) {
      center = (left + right) / 2;
      if (nums[center] == target)
        return center;
      else if (nums[center] > target)
        right = center - 1;
      else
        left = center + 1;
    }
    return left;
  }
};