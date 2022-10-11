class Solution {
 public:
  int firstUniqChar(string s) {
    vector<int> dict(26, 0);
    for (char ch : s) dict[ch - 'a']++;
    char ch;
    for (int i = 0; i < s.length(); i++) {
      ch = s[i];
      if (dict[ch - 'a'] == 1) return i;
    }
    return -1;
  }
};