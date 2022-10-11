// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
 public:
  int firstBadVersion(int n) {
    int left = 1, right = n, center;
    while (left <= right) {
      center = (right - left) / 2 + left;
      if (isBadVersion(center))
        right = center - 1;
      else
        left = center + 1;
    }
    return left;
  }
};