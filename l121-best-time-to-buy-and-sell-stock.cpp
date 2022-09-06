class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int minPrice = prices[0];
    int maxDiff = 0;
    for (int i = 1; i < prices.size(); i++) {
      maxDiff = max(maxDiff, prices[i] - minPrice);
      minPrice = min(minPrice, prices[i]);
    }
    return maxDiff;
  }
};