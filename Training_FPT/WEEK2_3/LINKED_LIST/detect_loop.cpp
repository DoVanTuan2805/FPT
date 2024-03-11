#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
};
void push(Node **head, int data)
{
    Node *newNode = new Node();
    newNode->data = data;

    /* link the old list of the new node */
    newNode->next = *head;
    /* move the head to point to the new node */
    *head = newNode;
}
int sizeList(Node *head)
{
    int count = 0;
    Node *currNode = head;
    while (currNode != NULL)
    {
        count++;
        currNode = currNode->next;
    }
    return count;
}
int getDataIndex(Node *head, int index)
{
    int count = 0;
    Node *currNode = head;
    while (currNode != NULL)
    {
        if (count == index)
        {
            return currNode->data;
        }
        count++;
        currNode = currNode->next;
    }
    assert(0);
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
            return true;
        }
    }
    return false;
}
int main()
{
    Node *head = NULL;
    push(&head, 10);
    push(&head, 1);
    push(&head, 3);
    push(&head, 5);
    push(&head, 23);

    /* Create a loop for testing(5 is pointing to 2) */
    head->next->next->next->next->next = head->next;

    if (detectLoop(head))
    {
        cout << "Loop List" << endl;
    }
    else
    {
        cout << "UnLoop List" << endl;
    }

    // cout << getDataIndex(head, 1) << endl;
    // cout << sizeList(head) << endl;
    return 0;
}