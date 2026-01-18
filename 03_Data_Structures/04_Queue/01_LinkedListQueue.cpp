#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class ListQueue
{
    Node *head;
    Node *tail;
    int count;

public:
    ListQueue()
    {
        head = tail = NULL;
        count = 0;
    }
    void push(int val); // add val to the queue
    void pop();         // remove val from the queue
    int front();        // returns the front value
    int back();         // returns the back value
    int size();         // returns size of the queue
    bool empty();       // checks that the queue is empty or not
    void print();

    ~ListQueue()
    {
        while (!empty())
            pop();
    }
};

void ListQueue ::push(int val) // enqueue
{
    Node *newNode = new Node(val);
    count++;
    
    if (tail == NULL)
    {
        head = tail = newNode;
        return;
    }

    tail->next = newNode;
    tail = newNode;
}

void ListQueue ::pop() // dequeue
{
    if (empty())
    {
        cout << "Queue is Empty!" << endl;
        return;
    }

    Node *temp = head;
    head = head->next;
    delete temp;
    count--;

    if (head == NULL)
        tail = NULL;
}

int ListQueue::front()
{
    if (empty())
    {
        cout << "Queue is Empty !" << endl;
        return -1;
    }
    return head->data;
}

int ListQueue::back()
{
    if (empty())
    {
        cout << "Queue is Empty !" << endl;
        return -1;
    }

    return tail->data;
}

int ListQueue::size()
{
    return count;
}

bool ListQueue::empty()
{
    return count == 0;
}

void ListQueue::print()
{
    if (empty())
    {
        cout << "Queue is Empty !" << endl;
        return;
    }

    Node *current = head;
    while (current != NULL)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main()
{
    ListQueue lq;

    lq.push(7);
    lq.push(11);
    lq.push(200);
    lq.push(6);

    lq.print();
    lq.pop();

    lq.push(8);
    lq.push(12);
    lq.push(200);
    lq.push(6);

    cout << lq.front() << endl;
    lq.print();
}