#include <iostream>
using namespace std;
// using Recursion
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

Node *createFromArray(int arr[], int size)
{
    Node *head = new Node(arr[0]);
    Node *current = head;
    for (int i = 1; i < size; i++)
    {
        current->next = new Node(arr[i]);
        current = current->next;
    }
    return head;
}

Node *reverseList(Node *head)
{
    if (head->next == NULL || head == NULL)
        return head;
    Node *newHead = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
}

void PrintList(Node *head)
{
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
    int arr[5] = {1, 2, 3, 4, 5};
    Node *head = createFromArray(arr, 5);
    cout << "A SLL created as following: ";
    PrintList(head);
    cout << "After reversing: ";
    PrintList(reverseList(head));
}