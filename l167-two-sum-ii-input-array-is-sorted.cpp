// binary search， O(NlogN), O(1)
class Solution {
 public:
  vector<int> twoSum(vector<int>& numbers, int target) {
    int left, right, center, val;
    for (int i = 0; i < numbers.size() - 1; i++) {
      val = target - numbers[i];
      left = i + 1;
      right = numbers.size() - 1;
      while (left <= right) {
        center = (left + right) / 2;
        if (numbers[center] == val)
          return vector<int>{i + 1, center + 1};
        else if (numbers[center] > val)
          right = center - 1;
        else
          left = center + 1;
      }
    }
    return vector<int>();
  }
};

// two pointers, O(N), O(1)
class Solution {
 public:
  vector<int> twoSum(vector<int>& numbers, int target) {
    int left = 0, right = numbers.size() - 1, sum;
    while (left < right) {
      if (numbers[left] >= 0 && numbers[right] > INT_MAX - numbers[left]) {
        right--;
      } else if (numbers[left] < 0 &&
                 numbers[right] < INT_MIN - numbers[left]) {
        left++;
      } else {
        sum = numbers[left] + numbers[right];
        if (sum == target) {
          return {left + 1, right + 1};
        } else if (sum < target) {
          left++;
        } else {
          right--;
        }
      }
    }
    return {-1, -1};
  }
};