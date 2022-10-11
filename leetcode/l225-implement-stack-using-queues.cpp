// two queues
class MyStack {
 public:
  MyStack() {}
  queue<int> queue1, queue2;
  bool inQueue1 = true;

  int move(bool delete_) {
    queue<int> &queueA = (inQueue1 ? queue1 : queue2);
    queue<int> &queueB = (inQueue1 ? queue2 : queue1);
    while (queueA.size() > 1) {
      queueB.push(queueA.front());
      queueA.pop();
    }
    int tmp = queueA.front();
    if (!delete_) {
      queueB.push(tmp);
    }
    queueA.pop();
    inQueue1 = !inQueue1;
    return tmp;
  }

  void push(int x) { (inQueue1 ? queue1 : queue2).push(x); }

  int pop() { return move(true); }

  int top() { return move(false); }

  bool empty() { return queue1.empty() && queue2.empty(); }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

// one stack with cache
class MyStack {
 public:
  MyStack() {}
  queue<int> fakeStack;
  bool cache = false;

  void sendBack(int n) {
    for (int i = 0; i < n; i++) {
      fakeStack.push(fakeStack.front());
      fakeStack.pop();
    }
  }

  void push(int x) {
    if (cache) {
      sendBack(1);
      cache = false;
    }
    fakeStack.push(x);
  }

  int pop() {
    if (!cache) {
      sendBack(fakeStack.size() - 1);
    }
    cache = false;
    int tmp = fakeStack.front();
    fakeStack.pop();
    return tmp;
  }

  int top() {
    if (!cache) {
      sendBack(fakeStack.size() - 1);
      cache = true;
    }
    return fakeStack.front();
  }

  bool empty() { return fakeStack.empty(); }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */