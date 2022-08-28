// naive solution
class Solution {
 public:
  int hammingWeight(uint32_t n) {
    int count = 0;
    while (n != 0) {
      count += n % 2;
      n = n >> 1;
    }
    return count;
  }
};

// flip the least-significant 1-bit (the rightmost 1-bit)
// example:
// 1 1 0 1 0 0 (n)
// 1 1 0 0 1 1 (n-1)
// 1 1 0 0 0 0 (n &(n-1))
class Solution {
 public:
  int hammingWeight(uint32_t n) {
    int count = 0;
    while (n != 0) {
      count++;
      n &= n - 1;
    }
    return count;
  }
};