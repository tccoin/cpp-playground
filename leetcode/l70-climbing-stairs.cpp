// naive brute force
class Solution {
 public:
  unordered_map<int, int> cache;
  int climbStairs(int n) {
    if (n == 1)
      return 1;
    else if (n == 2)
      return 2;
    if (cache.count(n) == 0) cache[n] = climbStairs(n - 1) + climbStairs(n - 2);
    return cache[n];
  }
};

// dynamic programming
class Solution {
 public:
  int climbStairs(int n) {
    if (n <= 2) return n;
    vector<int> cache(n + 1, 0);
    cache[1] = 1;
    cache[2] = 2;
    for (int i = 3; i < n + 1; i++) {
      cache[i] = cache[i - 1] + cache[i - 2];
    }
    return cache.back();
  }
};
