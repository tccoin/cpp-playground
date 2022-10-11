class Solution {
 public:
  int minCostClimbingStairs(vector<int>& cost) {
    int lastCost1 = cost[0];
    int lastCost2 = cost[1];
    int tmp = 0;
    for (int i = 2; i < cost.size(); i++) {
      tmp = min(lastCost1, lastCost2) + cost[i];
      lastCost1 = lastCost2;
      lastCost2 = tmp;
    }
    return min(lastCost1, lastCost2);
  }
};