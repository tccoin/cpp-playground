// naive solution
class Solution {
 public:
  int hammingDistance(int x, int y) {
    int distance = 0;
    for (int i = 0; i < 32; i++) {
      distance += ((x >> i) & 1) != ((y >> i) & 1);
    }
    return distance;
  }
};

// turn off rightmost bit of one
class Solution {
 public:
  int hammingDistance(int x, int y) {
    int distance = 0;
    int diff = x ^ y;
    while (diff != 0) {
      distance++;
      diff &= diff - 1;
    }
    return distance;
  }
};