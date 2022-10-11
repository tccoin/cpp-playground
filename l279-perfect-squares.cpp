class Solution {
 public:
  int numSquares(int n) {
    // calc squares
    vector<int> squares{0};
    int square = 0;
    int i;
    for (i = 1; i < 101; i++) {
      if (i * i < n) {
        squares.push_back(i * i);
      } else if (i * i == n) {
        return 1;
      } else {
        break;
      }
    }
    int maxSqrt = i - 1;
    // dp
    vector<int> dp(n + 1, 0);
    int count;
    for (i = 1; i <= n; i++) {
      count = n;
      for (int j = 1; j <= maxSqrt; j++) {
        if (i - squares[j] < 0) {
          break;
        }
        count = min(count, dp[i - squares[j]] + 1);
      }
      dp[i] = count;
    }

    return dp.back();
  }
};