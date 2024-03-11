#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
};
void createNode(Node **head, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));

    newNode->data = data;
    newNode->next = *(head); // lay dia chi cua head
    *head = newNode;         // gan head bang new node -> new node se la head
}
int main()
{
    Node *head = NULL; // tao head node
    createNode(&head, 10);
    createNode(&head, 5);
    createNode(&head, 1);
    createNode(&head, 20);

    int count = 0;
    Node *currentHead = head;
    while (currentHead != NULL)
    {
        currentHead = currentHead->next;
        count++;
    }
    cout << count << endl;
}