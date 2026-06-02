#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item
{
    int value, weight;
};

bool compareItem(const Item &a, const Item &b)
{
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

double fractionalKnapsack(int W, vector<Item> &arr)
{
    sort(arr.begin(), arr.end(), compareItem);

    double finalValue = 0.0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i].weight <= W)
        {
            W -= arr[i].weight;
            finalValue += arr[i].value;
        }
        else
        {
            finalValue += arr[i].value * ((double)W / arr[i].weight);
            break;
        }
    }
    return finalValue;
}

int main()
{
    int W = 50;
    vector<Item> arr = {{60, 10}, {100, 20}, {120, 30}};
    cout << "Maximum Value: " << fractionalKnapsack(W, arr) << "\n";
    return 0;
}
