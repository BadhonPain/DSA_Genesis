#include <iostream>
#include <stack>
#include <queue>
using namespace std;

queue<int> reverseFirstK(queue<int> q, int k)
{
    stack<int> st;

    for (int i = 0; i < k; i++)
    {
        st.push(q.front());
        q.pop();
    }

    while (!st.empty())
    {
        q.push(st.top());
        st.pop();
    }

    int rem = q.size() - k;
    for (int i = 0; i < rem; i++)
    {
        q.push(q.front());
        q.pop();
    }
    return q;
}

int main()
{
    queue<int> queue;
    queue.push(1);
    queue.push(2);
    queue.push(3);
    queue.push(4);
    queue.push(5);

    int k = 3;
    queue = reverseFirstK(queue, k);

    // Printing queue
    while (!queue.empty())
    {
        cout << queue.front() << " ";
        queue.pop();
    }
    return 0;
}