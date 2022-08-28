// brute-force
class Solution {
 public:
  vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int> tmp1, tmp2;
    vector<int> result;
    for (int num : nums1) tmp1.insert(num);
    for (int num : nums2)
      if (tmp1.count(num)) tmp2.insert(num);
    result.insert(result.end(), tmp2.begin(), tmp2.end());
    return result;
  }
};