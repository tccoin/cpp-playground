#include <iostream>
#include <vector>
using namespace std;

namespace dbnb {
istream& operator>>(istream& is, vector<int> dt) {
  int tmp;
  int i = 0;
  while (is && i < 3) {
    is >> tmp;
    dt.push_back(tmp);
    cout << tmp << endl;
    i++;
  }
  return is;
}
}  // namespace dbnb

int main() {
  using namespace dbnb;
  vector<int> nums;
  cin >> nums;
  cout << "over" << endl;
  for (int num : nums) {
    cout << num;
  }
  return 0;
}