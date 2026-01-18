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

class ListStack
{
    Node *head;
    int elem_count;

public:
    ListStack()
    {
        head = NULL;
        elem_count = 0;
    }
    bool isEmpty(); // checks stack is empty or not
    // bool isFull();      // Never a ListStack become full
    void push(int val); // add new value to stack
    void pop();         // remove last inserted value
    int peek();         // return the top value
    int size();         // return the size of the stack
    void print();       // print the Stack

    ~ListStack()
    {
        cout << "Destructing...." << endl;
        while (!isEmpty())
        {
            pop();
        }
    }
};

bool ListStack ::isEmpty()
{
    return head == NULL;
}

void ListStack ::push(int val)
{
    elem_count++;
    cout << val << " is pushed to the Stack" << endl;
    Node *newNode = new Node(val);
    if (isEmpty())
    {
        head = newNode;
        return;
    }
    newNode->next = head;
    head = newNode;
}

void ListStack ::pop()
{
    if (isEmpty())
    {
        cout << "Stack is Empty !" << endl;
        return;
    }
    cout << head->data << " is poped from the Stack" << endl;
    Node *temp = head;
    head = head->next;
    delete temp;
    elem_count--;
}

int ListStack ::peek()
{
    if (isEmpty())
    {
        cout << "Stack is Empty! " << endl;
        return -1;
    }
    return head->data;
}

int ListStack::size()
{
    return elem_count;
}

void ListStack ::print()
{
    if (isEmpty())
    {
        cout << "Stack is Empty !" << endl;
        return;
    }
    cout << "Stack: ";
    Node *current = head;
    while (current != NULL)
    {
        cout << current->data << "->";
        current = current->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    ListStack ls;
    ls.push(23);
    ls.push(35);
    ls.push(12);
    ls.push(49);
    ls.print();
    ls.pop();
    ls.pop();
    cout << "Size of the Stack: " << ls.size() << endl;
    cout << "Top value of the Stack: " << ls.peek() << endl;
    ls.print();
}
