// sum version
class Solution {
 public:
  char findTheDifference(string s, string t) {
    int sum = 0;
    for (char ch : t) sum += ch;
    for (char ch : s) sum -= ch;
    return sum;
  }
};

// XOR version
class Solution {
 public:
  char findTheDifference(string s, string t) {
    char r = 0;
    for (char ch : t) r ^= ch;
    for (char ch : s) r ^= ch;
    return r;
  }
};