#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;

} Node;

typedef struct
{
    Node *head;
    Node *tail;

} List;
void init(List *list)
{
    list->head = NULL;
    list->tail = NULL;
}
Node *createNode(int val)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}
void push_front(List *list, int val)
{
    Node *newNode = createNode(val);
    if (list->head == NULL)
        list->head = list->tail = newNode;
    else
    {
        newNode->next = list->head;
        list->head = newNode;
    }
}
void push_back(List *list, int val)
{
    Node *newNode = createNode(val);
    if (list->head == NULL)
        list->head = list->tail = newNode;
    else
    {
        list->tail->next = newNode;
        list->tail = newNode;
    }
}
void pop_front(List *list)
{
    if (list->head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    Node *temp = list->head;
    if (list->head->next == NULL)
        list->head = list->tail = NULL;
    else
        list->head = list->head->next;

    temp->next = NULL;
    free(temp);
}
void pop_back(List *list)
{
    if (list->head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    Node *temp1 = list->tail;
    if (list->head->next == NULL)
        list->head = list->tail = NULL;
    else
    {
        Node *temp2 = list->head;
        while (temp2->next != list->tail)
        {
            temp2 = temp2->next;
        }
        list->tail = temp2;
        list->tail->next = NULL;
        free(temp1);
    }
}
void insert(List *list, int val, int pos)
{
    if (pos == 0)
    {
        push_front(list, val);
        return;
    }
    Node *newNode = createNode(val);
    Node *temp = list->head;
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
    temp->next = newNode;
}

void print(List *list)
{
    Node *temp = list->head;
    while (temp != NULL)
    {
        printf("%d ->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    List ll;
    init(&ll);
    push_front(&ll, 5);
    push_front(&ll, 3);
    push_back(&ll, 8);
    push_back(&ll, 6);
    pop_front(&ll);
    pop_back(&ll);
    insert(&ll, 8, 2);
    insert(&ll, 9, 0);
    print(&ll);
    return 0;
}