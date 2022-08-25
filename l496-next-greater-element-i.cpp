// brute force
class Solution {
 public:
  vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    vector<int> result;
    map<int, int> value2index;
    int nextGreater;
    for (int i = 0; i < nums2.size(); i++) {
      value2index[nums2[i]] = i;
    }
    for (int num : nums1) {
      nextGreater = -1;
      for (int j = value2index[num] + 1; j < nums2.size(); j++) {
        if (nums2[j] > num) {
          nextGreater = nums2[j];
          break;
        }
      }
      result.push_back(nextGreater);
    }
    return result;
  }
};

// monotonous stack
class Solution {
 public:
  vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    vector<int> result;
    unordered_map<int, int> value2nextGreater;
    stack<int> small;
    for (int i = 0; i < nums2.size(); i++) {
      while (!small.empty() && nums2[i] > small.top()) {
        value2nextGreater[small.top()] = nums2[i];
        small.pop();
      }
      small.push(nums2[i]);
    }
    while (!small.empty()) {
      value2nextGreater[small.top()] = -1;
      small.pop();
    }
    for (int num : nums1) {
      result.push_back(value2nextGreater[num]);
    }
    return result;
  }
};