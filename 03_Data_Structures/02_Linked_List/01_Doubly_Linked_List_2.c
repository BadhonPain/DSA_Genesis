#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

typedef struct
{
    Node *head;
    Node *tail;
} Double_List;

Node *createNode(int val)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = NULL;
    newNode->prev = NULL;
}

void push_front(Double_List *dl, int val)
{
    Node *newNode = createNode(val);
    if (dl->head == NULL)
        dl->head = dl->tail = newNode;
    else
    {
        newNode->next = dl->head;
        dl->head->prev = newNode;
        dl->head = newNode;
    }
}

void push_back(Double_List *list, int val)
{
    Node *newNode = createNode(val);
    if (list->head == NULL)
        list->head = list->tail = newNode;
    else
    {
        list->tail->next = newNode;
        newNode->prev = list->tail;
        list->tail = newNode;
    }
}

void pop_front(Double_List *list)
{
    if (list->head == NULL)
    {
        printf("Empty list\n");
        return;
    }
    Node *temp = list->head;
    if (list->head->next == NULL)
        list->head = list->tail = NULL;
    else
    {
        list->head = list->head->next;
        list->head->prev = NULL;
    }
    temp->next = NULL;
    free(temp);
}

void pop_back(Double_List *list)
{
    if (list->head == NULL)
    {
        printf("Empty list\n");
        return;
    }
    Node *temp = list->tail;
    if (list->head->next == NULL)
        list->head = list->tail = NULL;
    else
    {
        list->tail = list->tail->prev;
        list->tail->next = NULL;
    }
    temp->prev = NULL;
    free(temp);
}

void insert(Double_List *lst, int val, int pos)
{
    if (pos == 0)
    {
        push_front(lst, val);
        return;
    }
    Node *newNode = createNode(val);
    Node *temp = lst->head;
    for (int i = 0; i < pos - 1; i++)
    {
        temp = temp->next;
        if (temp == NULL)
        {
            printf("Invalid index\n");
            free(newNode);
            return;
        }
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
}

void print(Double_List *dll)
{
    Node *temp = dll->head;
    while (temp != NULL)
    {
        printf("%d<=>", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    Double_List dll;
    dll.head = NULL;
    dll.tail = NULL;
    push_front(&dll, 3);
    push_front(&dll, 2);
    insert(&dll, 7, 1);
    push_back(&dll, 1);
    push_back(&dll, 4);
    pop_front(&dll);
    pop_back(&dll);
    print(&dll);
    return 0;
}