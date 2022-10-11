// sort
class Solution {
 public:
  int majorityElement(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    return nums[nums.size() / 2];
  }
};

// Boyer-Moore Voting Algorithm
class Solution {
 public:
  int majorityElement(vector<int>& nums) {
    int count = 1;
    int candidate = nums[0];
    for (int i = 1; i < nums.size(); i++) {
      count += nums[i] == candidate ? 1 : -1;
      if (count == 0) {
        count = 1;
        candidate = nums[i];
      }
    }
    return candidate;
  }
};