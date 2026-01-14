#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int value)
    {
        data = value;
        next = NULL;
    }
};
class List
{
    Node *head;
    Node *tail;

public:
    List()
    {
        head = NULL;
        tail = NULL;
    }

    void push_front(int val)
    {
        Node *newnode = new Node(val);
        if (head == NULL)
        {
            head = tail = newnode;
        }
        else
        {
            newnode->next = head;
            head = newnode;
        }
    }

    void push_back(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
            head = tail = newNode;
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop_front()
    {
        if (head == NULL)
        {
            cout << "List is empty\n";
            return;
        }
        Node *temp = head;
        if (head->next == NULL)
            head = tail = NULL;
        else
            head = head->next;

        temp->next = NULL;
        delete temp;
    }

    void pop_back()
    {
        if (head == NULL)
        {
            cout << "List is empty\n";
            return;
        }
        Node *TEMP = tail;
        if (head->next == NULL)
            head = tail = NULL;
        else
        {
            Node *temp = head;
            while ((temp->next) != tail)
            {
                temp = temp->next;
            }
            tail = temp;
            tail->next = NULL;
        }
        delete TEMP;
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
        for (int i = 0; i < pos - 1; i++)
        {
            temp = temp->next;
            if (temp == NULL)
            {
                cout << "Invalid index\n";
                delete newNode;
                return;
            }
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void print()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};
int main()
{
    List ll;
    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);
    ll.push_back(4);
    ll.push_back(5);
    ll.push_back(6);
    ll.insert(8, 3);
    ll.pop_front();
    ll.pop_back();
    ll.print();
}