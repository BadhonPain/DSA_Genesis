#include <iostream>
using namespace std;

class MaxHeap
{
    int *arr;
    int size;

    void maxHeapify(int i, int currentSize) // O(logn)
    {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int largest = i;

        if (left < currentSize && arr[left] > arr[i])
            largest = left;
        if (right < currentSize && arr[right] > arr[largest])
            largest = right;

        if (largest != i)
        {
            swap(arr[i], arr[largest]);
            maxHeapify(largest, currentSize);
        }
    }

    void buildHeap() // // O(n)
    {
        for (int i = size / 2 - 1; i >= 0; i--)
        {
            maxHeapify(i, size);
        }
    }

public:
    MaxHeap(int *A, int size)
    {
        this->size = size;
        arr = new int[size];
        for (int i = 0; i < size; i++)
        {
            arr[i] = A[i];
        }
        buildHeap();
    }

    void printHeap()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    int extractMin() // O(logn)
    {
        int oldMin = arr[0];
        arr[0] = arr[size - 1];
        size--;
        maxHeapify(0, size);

        cout << oldMin << " is extracted from Heap." << endl;
        return oldMin;
    }

    void heapSort() // O(nlogn)
    {
        buildHeap();

        int n = size - 1;
        for (int i = n; i >= 1; i--)
        {
            swap(arr[0], arr[i]);
            maxHeapify(0, i);
        }
    }


    ~MaxHeap()
    {
        cout << "Destructing...." << endl;
        delete[] arr;
    }
};

int main()
{
    int arr[6] = {3, 2, 1, 5, 6, 4};
    MaxHeap heap(arr, 6);
    cout << "Creted Heap: " << endl;
    heap.printHeap();
    cout << "Sorted: " << endl;
    heap.heapSort();
    heap.printHeap();
}