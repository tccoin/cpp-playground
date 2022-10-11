class Solution {
 public:
  string removeOuterParentheses(string s) {
    int layer = 0;
    string result;
    for (char ch : s) {
      if (ch == '(') {
        if (layer++) result.push_back(ch);
      } else {
        if (--layer) result.push_back(ch);
      }
    }
    return result;
  }
};