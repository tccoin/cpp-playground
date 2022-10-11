class Solution {
 public:
  int longestPalindrome(string s) {
    unordered_map<char, int> dict;
    for (char ch : s) dict[ch]++;
    bool hasSingle = false;
    int maxLength = 0;
    for (auto [ch, count] : dict) {
      maxLength += count / 2 * 2;
      if (count % 2 == 1) hasSingle = true;
    }
    if (hasSingle) maxLength++;
    return maxLength;
  }
};