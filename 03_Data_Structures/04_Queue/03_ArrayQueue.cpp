#include <iostream>
using namespace std;

class ArrayQueue
{
    int *data;
    int front, rear;
    int capacity;
    int count;

public:
    ArrayQueue(int capacity)
    {
        this->capacity = capacity;
        data = new int[capacity];
        front = 0;
        rear = -1;
        count = 0;
    }

    void enqueue(int val)
    {
        if (count == capacity)
        {
            cout << "Error: Overflow !" << endl;
            return;
        }

        rear = (rear + 1) % capacity;
        data[rear] = val;
        count++;

        cout << val << " is pushed into the queue." << endl;
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Error: Underflow !" << endl;
            return;
        }

        cout << data[front] << " is popped from the queue." << endl;

        front = (front + 1) % capacity;
        count--;
    }

    int frontile()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty !" << endl;
            return -1;
        }
        return data[front];
    }

    int back()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty !" << endl;
            return -1;
        }
        return data[rear];
    }

    int size()
    {
        return count;
    }

    bool isEmpty()
    {
        return count == 0;
    }

    void print()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty !" << endl;
            return;
        }

        for (int i = 0; i < count; i++)
        {
            cout << data[(front + i) % capacity] << " ";
        }
        cout << endl;
    }

    ~ArrayQueue()
    {
        delete[] data;
    }
};

int main()
{
    ArrayQueue q(5);
    q.enqueue(1);
    q.enqueue(2);
    cout << "Queue size: " << q.size() << endl;
    q.print();

    q.dequeue();
    q.print();

    q.dequeue();
    q.print();

    q.dequeue();
}