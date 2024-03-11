#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
};
void push(Node **head, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}
int countNodeInLoop(Node *list)
{
    int count = 1;
    Node *temp = list;
    while (temp->next != list)
    {
        count++;
        temp = temp->next;
    }
    return count;
}
bool detectLoop(Node *list)
{
    Node *slow_p = list, *fast_p = list;
    while (slow_p != NULL && fast_p != NULL && fast_p->next != NULL)
    {
        slow_p = slow_p->next;
        fast_p = fast_p->next->next;
        if (slow_p == fast_p)
        {
            cout << countNodeInLoop(slow_p) << endl;
            return true;
        }
    }
    return false;
}
int main()
{
    Node *head = NULL;
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 4);
    push(&head, 5);

    // 1 -> 2 -> 3 -> 4 -> 5

    // 5 to point 3
    head->next->next->next->next->next = head;

    if (detectLoop(head))
    {
        cout << "List is Loop" << endl;
    }
    else
    {
        cout << "List isnt Loop" << endl;
    }
    return 0;
}