#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
    int arr[9] = {1, 7, 2, 5, 3, 8, 0, 6, 4};
    vector<int> v(9);
    stack<int> st;
    for (int i = 9-1; i >= 0; i--)
    {
        while ( !st.empty() >0 && st.top() <= arr[i])
        {
            st.pop();
        }

        if (st.empty())
            v[i] = -1;
        else
        {
            v[i] = st.top();
        }
        st.push(arr[i]);
    }

    for (int x : v)
        cout << x << " ";
    cout << endl;
}