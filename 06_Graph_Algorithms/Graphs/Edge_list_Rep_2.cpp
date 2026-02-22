#include <iostream>
#include <vector>
#include <tuple>
using namespace std;
#define N 4
// weighted Directed
int main()
{
    vector<tuple<int, int, int>> edges;
    edges.push_back({0, 1, 5});
    edges.push_back({1, 2, 7});
    edges.push_back({1, 3, 6});
    edges.push_back({2, 3, 5});
    edges.push_back({3, 0, 2});

    for (auto v : edges)
    {
        cout << "{" << get<0>(v) << "," << get<1>(v) << "," << get<2>(v) << "} ";
        // {a,b,w} means there's an edge between a and b and the weight of the edge is w
    }
    cout << endl;
}