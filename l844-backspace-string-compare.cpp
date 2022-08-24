// O(N), O(N)
class Solution {
 public:
  bool backspaceCompare(string s, string t) {
    vector<string> input{s, t};
    vector<string> result(2, "");
    for (int i = 0; i < 2; i++) {
      string str = input[i];
      for (char ch : str) {
        if (ch == '#') {
          if (result[i].length() != 0) result[i].pop_back();
        } else {
          result[i].push_back(ch);
        }
      }
    }
    return result[0] == result[1];
  }
};

// O(N), O(1)
class Solution {
 public:
  bool backspaceCompare(string s, string t) {
    int indexS = 0, indexT = 0;
    int endS = s.length() - 1, endT = t.length() - 1;
    int charS, charT;
    int skip;
    while (true) {
      skip = 0;
      while (indexS <= endS) {
        if (skip == 0 && s[endS - indexS] != '#')
          break;
        else
          skip += s[endS - indexS] == '#' ? 1 : -1;
        indexS++;
      }
      skip = 0;
      while (indexT <= endT) {
        if (skip == 0 && t[endT - indexT] != '#')
          break;
        else
          skip += t[endT - indexT] == '#' ? 1 : -1;
        indexT++;
      }
      if ((indexS > endS) != (indexT > endT)) return false;
      if (indexS > endS && indexT > endT) return true;
      if (s[endS - indexS] != t[endT - indexT]) return false;
      indexS++;
      indexT++;
    }
    return true;
  }
};