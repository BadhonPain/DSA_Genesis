#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node(int val)
    {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

class ListDequeue
{
    Node *head;
    Node *tail;
    int count;

public:
    ListDequeue()
    {
        head = tail = nullptr;
        count = 0;
    }
    void push_back(int val);  // add val to the rear of the queue
    void push_front(int val); // add val to the start of the queue
    void pop_front();         // remove val from the front of the queue
    void pop_back();          // remove val from the rear of the queue
    int front();              // returns the front value
    int back();               // returns the back value
    int size();               // returns size of the queue
    bool isEmpty();           // checks that the queue is empty or not
    void print();

    ~ListDequeue()
    {
        while (!isEmpty())
            pop_front();
    }
};

void ListDequeue ::push_back(int val)
{
    Node *newNode = new Node(val);

    if (isEmpty())
    {
        head = tail = newNode;
    }
    else
    {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    count++;
}

void ListDequeue::push_front(int val)
{
    Node *newNode = new Node(val);
    if (isEmpty())
    {
        head = tail = newNode;
        return;
    }
    else
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    count++;
}

void ListDequeue ::pop_front()
{
    if (isEmpty())
    {
        cout << "Queue is isEmpty!" << endl;
        return;
    }

    Node *temp = head;
    head = head->next;
    if (head != nullptr)
        head->prev = nullptr;
    else
        tail = nullptr;
    delete temp;
    count--;
}

void ListDequeue ::pop_back()
{
    if (isEmpty())
    {
        cout << "Queue is isEmpty!" << endl;
        return;
    }

    Node *temp = tail;
    tail = tail->prev;
    if (tail != nullptr)
        tail->next = nullptr;
    else
        head = nullptr;
    delete temp;
    count--;
}

int ListDequeue::front()
{
    if (isEmpty())
    {
        cout << "Queue is isEmpty !" << endl;
        return -1;
    }
    return head->data;
}

int ListDequeue::back()
{
    if (isEmpty())
    {
        cout << "Queue is isEmpty !" << endl;
        return -1;
    }

    return tail->data;
}

int ListDequeue::size()
{
    return count;
}

bool ListDequeue::isEmpty()
{
    return count == 0;
}

void ListDequeue::print()
{
    if (isEmpty())
    {
        cout << "Queue is Empty !" << endl;
        return;
    }

    Node *current = head;
    while (current != nullptr)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main()
{
    ListDequeue dq;

    cout << "=== Initial State ===" << endl;
    dq.print();
    cout << "Is empty? " << (dq.isEmpty() ? "Yes" : "No") << endl;
    cout << "Size: " << dq.size() << endl << endl;

    cout << "=== Push Back Operations ===" << endl;
    dq.push_back(7);
    dq.push_back(11);
    dq.push_back(200);
    dq.push_back(6);
    dq.print();
    cout << "Front: " << dq.front() << ", Back: " << dq.back() << endl;
    cout << "Size: " << dq.size() << endl << endl;

    cout << "=== Pop Front ===" << endl;
    dq.pop_front();
    dq.print();
    cout << "Front: " << dq.front() << ", Back: " << dq.back() << endl;
    cout << "Size: " << dq.size() << endl << endl;

    cout << "=== Push Front Operations ===" << endl;
    dq.push_front(8);
    dq.push_front(200);
    dq.print();
    cout << "Front: " << dq.front() << ", Back: " << dq.back() << endl;
    cout << "Size: " << dq.size() << endl << endl;

    cout << "=== Push & Pop Combination ===" << endl;
    dq.push_back(12);
    dq.push_back(6);
    dq.pop_back();
    dq.pop_front();
    dq.print();
    cout << "Front: " << dq.front() << ", Back: " << dq.back() << endl;
    cout << "Size: " << dq.size() << endl << endl;

    cout << "=== Pop Until Empty ===" << endl;
    while (!dq.isEmpty())
    {
        cout << "Removing front: " << dq.front() << endl;
        dq.pop_front();
        dq.print();
    }

    cout << "Final state: " << endl;
    dq.print();
    cout << "Is empty? " << (dq.isEmpty() ? "Yes" : "No") << endl;
    cout << "Size: " << dq.size() << endl;

    return 0;
}