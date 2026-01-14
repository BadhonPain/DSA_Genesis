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

Node *createList(int arr[], int size)
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

int getValueAt(Node *head, int pos) // 0 based indexing
{
    Node *current = head;
    for (int i = 0; i < pos; i++)
        current = current->next;
    return current->data;
}

Node *getNodeAt(Node *head, int pos) // TC -> O(n)
{
    Node *current = head;
    int currentIdx = 0;
    while (current != NULL)
    {
        if (currentIdx == pos)
            return current;
        current = current->next;
        currentIdx++;
    }
    return NULL;
}

int indexOf(Node *head, int val) // 0 based indexing // TC -> O(n)
{
    Node *current = head;
    int idx = 0;
    while (current != NULL)
    {
        if (current->data == val)
            return idx;
        current = current->next;
        idx++;
    }
    return -1;
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

Node *insertAtHead(Node *head, int val) // TC -> O(1)
{
    Node *newNode = new Node(val);
    newNode->next = head;
    head = newNode;
    return head;
}

Node *insertAtPos(Node *head, int pos, int val) // TC -> O(n)
{
    if (pos == 0)
        return insertAtHead(head, val);
    Node *newNode = new Node(val);
    Node *prev = getNodeAt(head, pos - 1);
    if (prev != NULL)
    {
        newNode->next = prev->next;
        prev->next = newNode;
        return head;
    }
    return head;
}

Node *insertAtTail(Node *head, int val) // without tail pointer // TC -> O(n)
{
    Node *newNode = new Node(val);
    Node *current = head;
    while (current->next != NULL)
        current = current->next;
    current->next = newNode;
    return head;
}
int main()
{
    int arr[6] = {1, 2, 3, 4, 5};
    Node *newHead = createList(arr, 5);
    cout << "Link list created: ";
    PrintList(newHead);
    cout << "Value at index 3: " << getValueAt(newHead, 3) << endl;
    cout << "Index of 2 is: " << indexOf(newHead, 2) << endl;
    cout << "After inserting 0 at head: ";
    PrintList(insertAtHead(newHead, 0));
    cout << "After inserting 87 at index 3: ";
    PrintList(insertAtPos(newHead, 3, 87));
    cout << "After inserting 87 at tail: ";
    PrintList(insertAtTail(newHead, 87));
}