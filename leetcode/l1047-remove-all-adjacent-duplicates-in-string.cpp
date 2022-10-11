// using std::stack
class Solution {
 public:
  string removeDuplicates(string s) {
    stack<char> todo;
    string result = "";
    for (char ch : s) {
      if (!todo.empty()) {
        char last = todo.top();
        if (last == ch) {
          todo.pop();
          continue;
        }
      }
      todo.push(ch);
    }
    while (!todo.empty()) {
      result += todo.top();
      todo.pop();
    }
    reverse(result.begin(), result.end());
    return result;
  }
};

// actually, using string directly is better
class Solution {
 public:
  string removeDuplicates(string s) {
    string result = "";
    for (char ch : s) {
      if (result != "") {
        if (result.back() == ch) {
          result.pop_back();
          continue;
        }
      }
      result.push_back(ch);
    }
    return result;
  }
};