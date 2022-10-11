// ugly solution
class Solution {
 public:
  int nthUglyNumber(int n) {
    int count = 0;
    long i;
    set<long> ugly{1};
    while (count != n) {
      i = *(ugly.begin());
      ugly.erase(ugly.begin());
      ugly.insert(i * 2);
      ugly.insert(i * 3);
      ugly.insert(i * 5);
      count++;
    }
    return i;
  }
};

// dp
class Solution {
 public:
  int nthUglyNumber(int n) {
    int k2 = 0, k3 = 0, k5 = 0;
    vector<int> dp(n);
    dp[0] = 1;
    for (int i = 1; i < n; i++) {
      dp[i] = min(dp[k2] * 2, min(dp[k3] * 3, dp[k5] * 5));
      if (dp[i] == dp[k2] * 2) {
        k2++;
      }
      if (dp[i] == dp[k3] * 3) {
        k3++;
      }
      if (dp[i] == dp[k5] * 5) {
        k5++;
      }
    }
    return dp.back();
  }
};