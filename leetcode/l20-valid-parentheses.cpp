class Solution {
 public:
  bool isValid(string s) {
    stack<char> todo;
    for (char ch : s) {
      if (ch == '(' || ch == '[' || ch == '{') {
        todo.push(ch);
      } else {
        if (todo.empty()) return false;
        char last = todo.top();
        todo.pop();
        if (last == '(' && ch != ')' || last == '[' && ch != ']' ||
            last == '{' && ch != '}')
          return false;
      }
    }
    return todo.empty();
  }
};