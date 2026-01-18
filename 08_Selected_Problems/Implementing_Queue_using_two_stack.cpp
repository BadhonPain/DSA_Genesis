class MyQueue {
    stack<int> st1;
    stack<int> st2;

public:
    MyQueue() {}

    void push(int x) {
        while (!st2.empty()) {
            st1.push(st2.top());
            st2.pop();
        }
        st2.push(x);
        while (!st1.empty()) {
            st2.push(st1.top());
            st1.pop();
        }
    }

    int pop() {
        if (!st2.empty()) {
            int val = st2.top();
            st2.pop();
            return val;
        }
        return -1;
    }

    int peek() { return st2.top(); }

    bool empty() { return st2.empty(); }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */