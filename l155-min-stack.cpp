class MinStack {
 public:
  stack<int> stackMin, stackVal;

  MinStack() {}

  void push(int val) {
    stackVal.push(val);
    if (!stackMin.empty())
      stackMin.push(min(stackMin.top(), val));
    else
      stackMin.push(val);
  }

  void pop() {
    stackVal.pop();
    stackMin.pop();
  }

  int top() { return stackVal.top(); }

  int getMin() { return stackMin.top(); }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */