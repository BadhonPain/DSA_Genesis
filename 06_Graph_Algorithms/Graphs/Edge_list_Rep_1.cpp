#include <iostream>
#include <vector>
using namespace std;
#define N 4
// Unweighted Directed
int main()
{
    vector<pair<int, int>> adj;
    adj.push_back({0, 1});
    adj.push_back({1, 2});
    adj.push_back({1, 3});
    adj.push_back({2, 3});
    adj.push_back({3, 0});

    for (auto v : adj)
    {
        cout << "{" << v.first << "," << v.second << "} ";
        // {a,b} means there's an edge between a and b
    }
    cout << endl;
}