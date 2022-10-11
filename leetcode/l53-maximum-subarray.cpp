class Solution {
 public:
  int maxSubArray(vector<int>& nums) {
    int last = nums[0];
    int maxSum = nums[0];
    for (int i = 1; i < nums.size(); i++) {
      last = last < 0 ? nums[i] : last + nums[i];
      maxSum = max(maxSum, last);
    }
    return maxSum;
  }
};