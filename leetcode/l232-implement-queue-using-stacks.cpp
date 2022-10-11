class MyQueue {
 public:
  stack<int> stack1, stack2;
  MyQueue() {}

  void setPushMode(bool pushMode) {
    if (pushMode && stack2.empty()) {
      return;
    }
    if (!pushMode && stack1.empty()) {
      return;
    }
    if (pushMode) {
      // put elements in stack 1
      while (!stack2.empty()) {
        int tmp = stack2.top();
        stack2.pop();
        stack1.push(tmp);
      }
    } else {
      // put elements in stack 2
      while (!stack1.empty()) {
        int tmp = stack1.top();
        stack1.pop();
        stack2.push(tmp);
      }
    }
  }

  void push(int x) {
    setPushMode(true);
    stack1.push(x);
  }

  int pop() {
    setPushMode(false);
    int tmp = stack2.top();
    stack2.pop();
    return tmp;
  }

  int peek() {
    setPushMode(false);
    return stack2.top();
  }

  bool empty() { return stack1.empty() && stack2.empty(); }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */