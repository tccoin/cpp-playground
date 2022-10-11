#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
int main() {
  vector<int> v1 = {20, 30, 40, 25, 15, 10, 5};
  // max heap
  make_heap(v1.begin(), v1.end());
  for (int &x : v1) cout << x << " ";
  cout << endl;

  // pop
  pop_heap(v1.begin(), v1.end());
  for (int &x : v1) cout << x << " ";
  cout << endl;

  // min heap
  make_heap(v1.begin(), v1.end(), greater<>{});
  for (int &x : v1) cout << x << " ";
  cout << endl;

  // pop
  pop_heap(v1.begin(), v1.end());
  for (int &x : v1) cout << x << " ";
  cout << endl;

  return 0;
}