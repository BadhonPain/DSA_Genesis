#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// A utility function to get the maximum value in arr[]

int getMax(const vector<int>& arr) {
    int maxVal = arr[0];
    for (int x : arr) {
        if (x > maxVal) maxVal = x;
    }
    return maxVal;
}

// A function to do counting sort of arr[] according to the digit represented by exp
void countingSortForRadix(vector<int>& arr, int exp) {
    int n = arr.size();
    vector<int> output(n);
    int count[10] = {0};

    // Store count of occurrences in count[]
    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    // Change count[i] so that count[i] now contains actual position of this digit in output[]
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Build the output array (traverse backwards to preserve stability)
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy the output array to arr[], so that arr[] now contains sorted numbers according to current digit
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

// Radix Sort - O(d * (n + b)) where d is digits, b is base (10)
// Works on non-negative integers

void radixSort(vector<int>& arr) {
    if (arr.empty()) return;

    // Find the maximum number to know number of digits
    int maxVal = getMax(arr);

    // Do counting sort for every digit. Instead of passing digit number, exp is passed.
    // exp is 10^i where i is current digit number
    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        countingSortForRadix(arr, exp);
    }
}

void printArray(const vector<int>& arr) {
    for (int x : arr) cout << x << " ";
    cout << "\n";
}

int main() {
    vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};

    cout << "Before: ";
    printArray(arr);

    radixSort(arr);

    cout << "After:  ";
    printArray(arr);

    return 0;
}
