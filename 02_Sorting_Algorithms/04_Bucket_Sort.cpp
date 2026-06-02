#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Bucket Sort - O(n + k) average, O(n^2) worst case
// Typically used for uniformly distributed floating-point numbers in a range like [0, 1)

void bucketSort(vector<float>& arr) {
    int n = arr.size();
    if (n <= 0) return;

    // 1) Create n empty buckets
    vector<vector<float>> buckets(n);

    // 2) Put array elements in different buckets based on index n * arr[i]
    for (int i = 0; i < n; i++) {
        int bucketIndex = n * arr[i]; // Index in bucket
        if (bucketIndex >= n) {
            bucketIndex = n - 1; // Safeguard for edge case arr[i] == 1.0
        }
        buckets[bucketIndex].push_back(arr[i]);
    }

    // 3) Sort individual buckets using built-in stable sort (or insertion sort)
    for (int i = 0; i < n; i++) {
        sort(buckets[i].begin(), buckets[i].end());
    }

    // 4) Concatenate all buckets into arr[]
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < buckets[i].size(); j++) {
            arr[index++] = buckets[i][j];
        }
    }
}

void printArray(const vector<float>& arr) {
    for (float x : arr) cout << x << " ";
    cout << "\n";
}

int main() {
    vector<float> arr = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};

    cout << "Before: ";
    printArray(arr);

    bucketSort(arr);

    cout << "After:  ";
    printArray(arr);

    return 0;
}
