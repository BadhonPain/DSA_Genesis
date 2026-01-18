#include <stack>
using namespace std;

// Insert an element at the bottom of the stack
void insertAtBottom(stack<int>& st, int x) {
    // Base case
    if (st.empty()) {
        st.push(x);
        return;
    }

    int top = st.top();
    st.pop();

    insertAtBottom(st, x);

    st.push(top);
}

// Reverse the stack using recursion
void reverseStack(stack<int>& st) {
    // Base case
    if (st.empty()) {
        return;
    }

    int top = st.top();
    st.pop();

    reverseStack(st);

    insertAtBottom(st, top);
}
