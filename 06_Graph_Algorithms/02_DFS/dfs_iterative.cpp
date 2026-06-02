#include<bits/stdc++.h>
using namespace std;

void dfs(int source,int visited[], const vector<vector<int>> &vc)
{
    visited[source] = 1;
    stack<int>st;
    st.push(source);
    while (!st.empty())
    {
        int u = st.top();
        st.pop();
        cout<<u<<" ";

        for(auto &x : vc[u])
        {
            if(!visited[x])
            {
                visited[x] = 1;
                st.push(x);
            }
        }

    }
    
}

int main()
{
    int v, e;
    cin >> v >> e;

    vector<vector<int>> vc(v + 1);
    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        vc[a].push_back(b);
        vc[b].push_back(a); // remove this if directed
    }

    int visited[v + 1];
    memset(visited, 0, sizeof(visited));

    cout << "Enter Starting Node(1-" << v << "): ";
    int source;
    cin >> source;
    dfs(source, visited, vc);
    cout << "\nVisited list: " << endl;
    for (int i = 1; i <= v; i++)
    {
        cout << i << ":" << visited[i] << endl;
    }
}