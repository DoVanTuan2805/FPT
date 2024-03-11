#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
};
void printAllNode(Node *head)
{
    while (head != NULL)
    {
        printf("%d - ", head->data);
        head = head->next;
    }
    printf("\n");
}
Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}
void insertFirstList(Node **head, int data)
{
    Node *newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}
void insetPrevList(Node *prevNode, int data)
{
    if (prevNode == NULL)
    {
        return;
    }
    Node *newNode = createNode(data);

    newNode->next = prevNode->next;
    prevNode->next = newNode;
}
void insertEndList(Node **head, int data)
{
    Node *newNode = createNode(data);

    Node *currNode = *head;
    if (currNode == NULL)
    {
        *head = newNode;
        return;
    }

    while (currNode->next != NULL)
    {
        currNode = currNode->next;
    }
    currNode->next = newNode;
    return;
}
void insertListIndex(Node **head, int index, int data)
{
    Node *newNode = createNode(data);

    Node *currNode = *head;
    for (int i = 0; i < index; i++)
    {
        if (currNode->next != NULL)
            currNode = currNode->next;
    }
    newNode->next = currNode->next;
    currNode->next = newNode;
}
int main()
{
    Node *head = NULL;
    insertFirstList(&head, 1);
    insertFirstList(&head, 2);
    insertFirstList(&head, 3);
    insertFirstList(&head, 4);
    insertFirstList(&head, 5);
    insertEndList(&head, 8);
    insetPrevList(head->next->next, 10);
    insertListIndex(&head, 6, 100);
    printAllNode(head);
    return 0;
}