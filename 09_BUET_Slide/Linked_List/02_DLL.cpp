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
        prev = next = NULL;
    }
};

Node *createList(int arr[], int size)
{
    Node *head = new Node(arr[0]);
    Node *current = head;
    for (int i = 1; i < size; i++)
    {
        current->next = new Node(arr[i]);
        current->next->prev = current;
        current = current->next;
    }

    return head;
}

void PrintList(Node *head)
{
    Node *current = head;
    while (current != NULL)
    {
        cout << current->data << "<->";
        current = current->next;
    }
    cout << "NULL" << endl;
}
int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    Node *head = createList(arr, 5);
    PrintList(head);
}