#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Counting Sort — O(n + k) time, O(k) space
// Works only for non-negative integers within a known range k

void countingSort(vector<int> &arr)
{
    if (arr.empty())
        return;

    int maxVal = *max_element(arr.begin(), arr.end());
    int minVal = *min_element(arr.begin(), arr.end());
    int range = maxVal - minVal + 1;

    vector<int> count(range, 0);

    // Step 1: Count occurrences
    for (int x : arr)
        count[x - minVal]++;

    // Step 2: Accumulate (prefix sum) — turns counts into positions
    for (int i = 1; i < range; i++)
        count[i] += count[i - 1];

    // Step 3: Build sorted output (iterate reverse for stability)
    vector<int> output(arr.size());
    for (int i = (int)arr.size() - 1; i >= 0; i--)
    {
        output[count[arr[i] - minVal] - 1] = arr[i];
        count[arr[i] - minVal]--;
    }

    arr = output;
}

void printArray(const vector<int> &arr)
{
    for (int x : arr)
        cout << x << " ";
    cout << "\n";
}

int main()
{
    vector<int> arr = {4, 2, 2, 8, 3, 3, 1};

    cout << "Before: ";
    printArray(arr);

    countingSort(arr);

    cout << "After:  ";
    printArray(arr);

    // Edge case: negative numbers supported via minVal offset
    vector<int> arr2 = {-3, -1, 0, 2, -2, 1};
    cout << "\nBefore (with negatives): ";
    printArray(arr2);
    countingSort(arr2);
    cout << "After:                   ";
    printArray(arr2);

    return 0;
}
