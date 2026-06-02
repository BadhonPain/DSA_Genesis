#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> arr = {5, 2, 8, 1, 3};

    // Lambda capturing nothing, sorting in descending order
    sort(arr.begin(), arr.end(), [](int a, int b)
         { return a > b; });

    cout << "Sorted Descending: ";
    for (int x : arr)
        cout << x << " ";
    cout << "\n";

    // Lambda capturing by reference
    int threshold = 3;
    int count = 0;
    for_each(arr.begin(), arr.end(), [threshold, &count](int x)
             {
        if (x > threshold) {
            count++;
        } });
    cout << "Elements greater than " << threshold << ": " << count << "\n";

    return 0;
}
