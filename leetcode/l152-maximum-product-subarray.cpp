class Solution {
 public:
  int maxProduct(vector<int>& nums) {
    vector<int> dp1(nums.size(), 1);
    vector<int> dp2(nums.size(), 0);
    dp1[0] = nums[0];
    dp2[0] = nums[0];
    for (int i = 1; i < nums.size(); i++) {
      dp1[i] = max(nums[i], dp1[i - 1] * nums[i]);
      dp1[i] = max(dp1[i], dp2[i - 1] * nums[i]);
      dp2[i] = min(nums[i], dp2[i - 1] * nums[i]);
      dp2[i] = min(dp2[i], dp1[i - 1] * nums[i]);
    }
    return *max_element(dp1.begin(), dp1.end());
  }
};