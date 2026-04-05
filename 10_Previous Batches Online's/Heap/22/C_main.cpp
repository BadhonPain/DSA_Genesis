#include <iostream>
using namespace std;

class Maxheap
{
    int *arr;
    int size;
    int capacity;

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
        for (int i = size / 2 - 1; i >= 0; i--)
        {
            maxHeapify(i);
        }
    }

public:
    Maxheap(int *A, int size)
    {
        this->size = 0;
        capacity = size;
        arr = new int[capacity];
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
    }

    int extractMax() // O(logn)
    {
        int oldMax = arr[0];
        arr[0] = arr[size - 1];
        size--;
        maxHeapify(0);

        return oldMax;
    }

    ~Maxheap()
    {
        cout << "Destructing...." << endl;
        delete[] arr;
    }
};

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    Maxheap heap(arr, 0);
    for (int i = 0; i < n; i++)
    {
        heap.insert(arr[i]);
        if (i < 2)
            cout << -1 << " ";

        else
        {
            int a = heap.extractMax();
            int b = heap.extractMax();
            int c = heap.extractMax();
            cout << a * b * c << " ";
            heap.insert(a);
            heap.insert(b);
            heap.insert(c);
        }
    }
    cout << endl;
}