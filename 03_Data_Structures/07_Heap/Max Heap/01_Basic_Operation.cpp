#include <iostream>
using namespace std;

class Maxheap
{
    int *arr;
    int size;

    void maxHeapify(int i) // O(logn)
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
            maxHeapify(largest);
        }
    }

    void buildHeap() // // O(n)
    {
        cout << "Building Heap..." << endl;
        for (int i = size / 2 - 1; i >= 0; i--)
        {
            maxHeapify(i);
        }
    }

public:
    Maxheap(int *A, int size)
    {
        this->size = size;
        arr = new int[size];
        for (int i = 0; i < size; i++)
        {
            arr[i] = A[i];
        }
        buildHeapByInsertion();
    }

    int getMaximum()
    {
        return arr[0];
    }

    void printHeap()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void insert(int item) // O(logn)
    {
        size++;
        arr[size - 1] = item;
        int n = size - 1;
        while (true)
        {
            if (arr[(n - 1) / 2] < arr[n])
            {
                swap(arr[n], arr[(n - 1) / 2]);
                n = (n - 1) / 2;
            }
            else
                break;
        }
        cout << item << " is inserted." << endl;
    }

    int extractMax() // O(logn)
    {
        int oldMax = arr[0];
        arr[0] = arr[size - 1];
        size--;
        maxHeapify(0);

        cout << oldMax << " is extracted from Heap." << endl;
        return oldMax;
    }

    void buildHeapByInsertion() // O(nlogn)
    {
        cout << "Heap is building by insertion..." << endl;
        int finalSize = this->size;
        this->size = 0;

        for (int i = 0; i < finalSize; i++)
        {
            int valueToInsert = arr[i];
            insert(valueToInsert);
        }
    }

    ~Maxheap()
    {
        cout << "Destructing...." << endl;
        delete[] arr;
    }
};

int main()
{
    int arr[6] = {3, 2, 1, 5, 6, 4};
    Maxheap heap(arr, 6);
    cout << "Creted Heap: " << endl;
    heap.printHeap();
    cout << "Maximum/Top/Peek: " << heap.getMaximum() << endl;
    heap.insert(36);
    cout << "After insertion : " << endl;
    heap.printHeap();
    cout << "Extract Max: " << heap.extractMax() << endl;
    cout << "After extracting : " << endl;
    heap.printHeap();
}