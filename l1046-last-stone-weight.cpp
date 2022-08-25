class Solution {
 public:
  int lastStoneWeight(vector<int>& stones) {
    priority_queue<int> q;
    for (int stone : stones) q.push(stone);
    int stone1, stone2;
    while (q.size() > 1) {
      stone1 = q.top();
      q.pop();
      stone2 = q.top();
      q.pop();
      if (stone1 != stone2) q.push(abs(stone1 - stone2));
    }
    return q.size() == 0 ? 0 : q.top();
  }
};