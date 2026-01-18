#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
    stack<int> st;

public:
    void push(int x) {
        st.push(x);
    }

    int pop() {
        if (st.empty()) return -1; 

        int x = st.top();
        st.pop();

        if (st.empty()) {
            return x;
        }

        int res = pop(); 
        st.push(x);      
        return res;
    }

    int peek() {
        if (st.empty()) return -1;

        int x = st.top();
        st.pop();

        if (st.empty()) {
            st.push(x);
            return x;   
        }

        int res = peek();
        st.push(x); 
        return res;
    }

    bool empty() {
        return st.empty();
    }
};

int main() {
    MyQueue q;
    q.push(10);
    q.push(20);
    q.push(30);

    cout << q.pop() << endl; 
    cout << q.peek() << endl; 
    q.push(40);
    cout << q.pop() << endl; 
    cout << q.pop() << endl; 
    cout << q.pop() << endl; 
    cout << q.empty() << endl; 

    return 0;
}
