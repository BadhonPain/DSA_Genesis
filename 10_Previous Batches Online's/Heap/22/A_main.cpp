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
        buildHeap();
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

    int maxPossibleSale(int k)
    {
        int totalSale = 0;
        for (int i = 0; i < k; i++)
        {
            int sale = extractMax();
            totalSale += sale;
            insert(sale - 1);
        }
        return totalSale;
    }

    ~Maxheap()
    {
        cout << "Destructing...." << endl;
        delete[] arr;
    }
};

int main()
{
    int m, n;
    cin >> m >> n;
    int arr[m];
    for (int i = 0; i < m; i++)
    {
        cin >> arr[i];
    }

    Maxheap heap(arr, m);
    cout << heap.maxPossibleSale(n) << endl;
}