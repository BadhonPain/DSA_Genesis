#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> st;
    st.push(2);
    st.push(4);
    st.push(5);
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
    st.push(6);
    cout << st.size();
}