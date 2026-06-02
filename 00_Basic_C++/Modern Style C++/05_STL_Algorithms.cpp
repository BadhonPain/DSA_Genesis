#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};

    // std::all_of, std::any_of (Modern STL)
    bool allPositive = all_of(arr.begin(), arr.end(), [](int x) { return x > 0; });
    bool hasEven = any_of(arr.begin(), arr.end(), [](int x) { return x % 2 == 0; });

    cout << "All Positive: " << (allPositive ? "Yes" : "No") << "\n";
    cout << "Has Even: " << (hasEven ? "Yes" : "No") << "\n";

    // std::iota to populate sequence
    vector<int> seq(5);
    iota(seq.begin(), seq.end(), 10); // fills with 10, 11, 12, 13, 14
    cout << "Sequence: ";
    for (int x : seq) cout << x << " ";
    cout << "\n";

    return 0;
}
