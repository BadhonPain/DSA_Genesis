#include <iostream>
using namespace std;

class MinHeap
{
    int *arr;
    int size;

    void minHeapify(int i, int currentSize) // O(logn)
    {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;

        if (left < currentSize&& arr[left] < arr[i])
            smallest = left;
        if (right < currentSize&& arr[right] < arr[smallest])
            smallest = right;

        if (smallest != i)
        {
            swap(arr[i], arr[smallest]);
            minHeapify(smallest,currentSize);
        }
    }

    void buildHeap() // // O(n)
    {
        for (int i = size / 2 - 1; i >= 0; i--)
        {
            minHeapify(i,size);
        }
    }

public:
    MinHeap(int *A, int size)
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
        minHeapify(0,size);

        cout << oldMin << " is extracted from Heap." << endl;
        return oldMin;
    }

    void heapSort()
    {
        buildHeap();
        int n = size - 1;

        for (int i = n; i >= 1; i--)
        {
            swap(arr[0], arr[i]);
            minHeapify(0,i);
        }
    }

    ~MinHeap()
    {
        cout << "Destructing...." << endl;
        delete[] arr;
    }
};

int main()
{
    int arr[6] = {3, 2, 1, 5, 6, 4};
    MinHeap heap(arr, 6);
    cout << "Creted Heap: " << endl;
    heap.printHeap();
    cout << "Sorted: " << endl;
    heap.heapSort();
    heap.printHeap();
}