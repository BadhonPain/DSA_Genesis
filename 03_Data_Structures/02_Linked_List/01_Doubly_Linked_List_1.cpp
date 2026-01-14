#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int val)
    {
        data = val;
        next = prev = NULL;
    }
};

class doubly_ll
{
    Node *head;
    Node *tail;

public:
    doubly_ll()
    {
        head = NULL;
        tail = NULL;
    }
    void push_front(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
            head = tail = newNode;
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void print()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "<=>";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void push_back(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
            head = tail = newNode;
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void pop_front()
    {
        if (head == NULL)
        {
            cout << "The list is empty\n";
            return;
        }
        Node *temp = head;
        if (head->next == NULL)
            head = tail = NULL;
        else
        {
            head = head->next;
            head->prev = NULL;
        }
        temp->next = NULL;
        delete temp;
    }

    void pop_back()
    {
        if (head == NULL) // for empty linked list
        {
            cout << "The list is empty\n";
            return;
        }
        Node *temp = tail;
        if (head->next == NULL) // for single noded linked list
            head = tail = NULL;
        else
        {
            tail = tail->prev;
            tail->next = NULL;
        }
        temp->prev = NULL;
        delete temp;
    }
    void insert(int val, int pos)
    {
        if (pos == 0)
        {
            push_front(val);
            return;
        }
        Node *newNode = new Node(val);
        Node *temp = head;
        for (int i = 0; i < pos; i++)
        {
            temp = temp->next;
            if (temp == NULL)
            {
                cout << "Invalid index\n"
                     << endl;
                delete newNode;
                return;
            }
        }
        newNode->next = temp;
        newNode->prev = temp->prev;
        temp->prev->next = newNode;
        temp->prev = newNode;
    }
};

int main()
{
    doubly_ll dll;
    dll.push_front(3);
    dll.push_front(2);
    dll.push_front(1);
    dll.push_back(4);
    dll.push_back(5);
    dll.insert(7, 2);
    dll.pop_front();
    dll.pop_front();
    dll.pop_back();
    dll.pop_back();
    dll.print();
}