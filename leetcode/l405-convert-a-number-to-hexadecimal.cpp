class Solution {
 public:
  string toHex(int num) {
    int byte;
    string result;
    for (int i = 0; i < 8; i++) {
      byte = (num >> (28 - 4 * i)) & 0xf;
      if (byte == 0 && result.size() == 0) continue;
      result.push_back(byte < 10 ? '0' + byte : 'a' + (byte - 10));
    }
    return result.size() == 0 ? "0" : result;
  }
};