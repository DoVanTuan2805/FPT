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
        printf("%d ", node->data);
        node = node->next;
    }
}
Node *createNode(int data)
{
    Node *node = new Node();
    node->data = data;
    node->next = NULL;

    return node;
}
void insertFirstList(Node **head, int data)
{
    Node *newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}
void reserveList(Node **head)
{
    Node *current = *head;
    Node *next = NULL;
    Node *previous = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    *head = previous;
}
int main()
{
    Node *head = NULL;
    int t, n, num;
    cin >> t >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        insertFirstList(&head, num);
    }

    reserveList(&head);
    printAllList(head);
    return 0;
}