class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int hold = -1 * prices[0];
    int nothold = 0;
    int cooldown = -10000;
    int tmp;
    for (int i = 1; i < prices.size(); i++) {
      tmp = hold + prices[i];
      hold = max(hold, nothold - prices[i]);
      nothold = max(nothold, cooldown);
      cooldown = tmp;
    }
    return max(hold, max(nothold, cooldown));
  }
};