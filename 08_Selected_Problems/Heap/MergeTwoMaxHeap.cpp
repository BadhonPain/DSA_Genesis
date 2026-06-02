#include <iostream>
using namespace std;

const int SIZE_1 = 7;
const int SIZE_2 = 5;
const int TOTAL_SIZE = SIZE_1 + SIZE_2;

void maxHeapify(int *arr, int size, int i)
{
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int largest = i;

    if (left < size && arr[left] > arr[i])
        largest = left;
    if (right < size && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        maxHeapify(arr, size, largest);
    }
}

void buildMergedHeap(int *arr, int size)
{
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        maxHeapify(arr, size, i);
    }
}

int main()
{
    int maxHeap1[SIZE_1] = {90, 85, 70, 45, 50, 60, 20};
    int maxHeap2[SIZE_2] = {100, 40, 95, 30, 10};

    int mergedMaxHeap[TOTAL_SIZE];
    for (int i = 0; i < SIZE_1; i++)
    {
        mergedMaxHeap[i] = maxHeap1[i];
    }

    for (int i = 0; i < SIZE_2; i++)
    {
        mergedMaxHeap[SIZE_1 + i] = maxHeap2[i];
    }
    buildMergedHeap(mergedMaxHeap, TOTAL_SIZE); // O(SIZE_1+SIZE_2)

    for (int i = 0; i < TOTAL_SIZE; i++)
    {
        cout << mergedMaxHeap[i] << " ";
    }
}