class Solution {
 public:
  bool wordBreak(string s, vector<string>& wordDict) {
    string curr = "";
    vector<bool> dp(s.size() + 1, false);
    dp[0] = true;
    int start;
    for (int i = 0; i < s.length(); i++) {
      curr.push_back(s[i]);
      for (string& word : wordDict) {
        start = curr.size() - word.size();
        if (start >= 0 && dp[start] && curr.size() - start == word.size() &&
            curr.substr(start, word.size()) == word)
          dp[curr.size()] = true;
      }
    }
    return dp.back();
  }
};