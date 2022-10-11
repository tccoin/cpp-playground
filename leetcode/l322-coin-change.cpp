class Solution {
 public:
  int coinChange(vector<int>& coins, int amount) {
    const int MAX = amount + 1;
    if (coins.size() == 1) {
      return (amount % coins[0] == 0) ? (amount / coins[0]) : -1;
    }
    vector<int> dp(amount + 1, MAX);
    dp[0] = 0;
    int minCoins;
    for (int i = 1; i < amount + 1; i++) {
      minCoins = MAX;
      for (int coin : coins) {
        if (i - coin >= 0) {
          minCoins = min(minCoins, dp[i - coin] + 1);
        }
      }
      dp[i] = minCoins;
    }
    return dp[amount] != MAX ? dp[amount] : -1;
  }
};