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

class ListDequeue
{
    Node *head;
    Node *tail;
    int count;

public:
    ListDequeue()
    {
        head = tail = NULL;
        count = 0;
    }
    void push_back(int val); // add val to the end of the queue
    void push_front(int val); // add val to the start of the queue
    void pop_front();         // remove val from the queue
    int front();        // returns the front value
    int back();         // returns the back value
    int size();         // returns size of the queue
    bool empty();       // checks that the queue is empty or not
    void print();

    ~ListDequeue()
    {
        while (!empty())
            pop_front();
    }
};

void ListDequeue ::push_back(int val) 
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

void ListDequeue::push_front(int val)
{
    
}

void ListDequeue ::pop_front() 
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

int ListDequeue::front()
{
    if (empty())
    {
        cout << "Queue is Empty !" << endl;
        return -1;
    }
    return head->data;
}

int ListDequeue::back()
{
    if (empty())
    {
        cout << "Queue is Empty !" << endl;
        return -1;
    }

    return tail->data;
}

int ListDequeue::size()
{
    return count;
}

bool ListDequeue::empty()
{
    return count == 0;
}

void ListDequeue::print()
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
    ListDequeue dq;

    dq.push_back(7);
    dq.push_back(11);
    dq.push_back(200);
    dq.push_back(6);

    dq.print();
    dq.pop_front();

    dq.push_back(8);
    dq.push_back(12);
    dq.push_back(200);
    dq.push_back(6);

    cout << dq.front() << endl;
    dq.print();
}