#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
};
void printAllList(Node *node)
{
    while (node != NULL)
    {
        printf("%d - ", node->data);
        node = node->next;
    }
}
Node *createNode(int newData)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = newData;
    newNode->next = NULL;
    return newNode;
}
void insertFirstList(Node **head, int data)
{
    Node *node = createNode(data);
    node->next = *head;
    *head = node;
}
bool searchNumInList(Node *head, int data)
{
    if (head == NULL)
    {
        return false;
    }
    Node *currNode = head;
    while (currNode->next != NULL)
    {
        if (currNode->data == data)
        {
            return true;
        }
        currNode = currNode->next;
    }
    return false;
}
int main()
{
    Node *head = NULL;
    insertFirstList(&head, 1);
    insertFirstList(&head, 2);
    insertFirstList(&head, 3);
    insertFirstList(&head, 7);

    cout << searchNumInList(head, 9) << endl;

    printAllList(head);
    return 0;
}