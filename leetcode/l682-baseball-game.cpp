// this question is in no sense related to baseball...
class Solution {
 public:
  int calPoints(vector<string>& ops) {
    vector<int> record;
    for (string op : ops) {
      if (op == "+") {
        record.push_back(record.back() + *(record.rbegin() + 1));
      } else if (op == "D") {
        record.push_back(record.back() * 2);
      } else if (op == "C") {
        record.pop_back();
      } else {
        record.push_back(stoi(op));
      }
    }
    return accumulate(record.begin(), record.end(), 0);
  }
};