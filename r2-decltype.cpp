#include <boost/core/type_name.hpp>
#include <iostream>

using namespace std;

int main() {
  int i = 42;
  int *p = &i;
  int &r = i;
  decltype(r) b = i;  // b is reference which requires initialization
  decltype(r + 0) c;
  decltype(p) d;
  cout << boost::core::type_name<decltype(b)>() << endl;
  cout << boost::core::type_name<decltype(c)>() << endl;
  cout << boost::core::type_name<decltype(d)>() << endl;
}