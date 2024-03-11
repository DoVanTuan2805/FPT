#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
};
ListNode *createNode(int val)
{
    ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));
    newNode->val = val;
    newNode->next = nullptr;
    return newNode;
}
void insertNodeFirst(ListNode **head, int val)
{
    ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));
    newNode->val = val;
    newNode->next = *head;
    *head = newNode;
}
void reverseNode(ListNode **head)
{
    ListNode *curr = *head;
    ListNode *prev = nullptr;
    while (curr != nullptr)
    {
        ListNode *nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    *head = prev;
}
void printAll(ListNode *head)
{
    while (head != nullptr)
    {
        cout << " " << head->val;
        head = head->next;
    }
    cout << endl;
}
ListNode *detecNodeInLoop(ListNode *head)
{
    ListNode *slowNode = head;
    ListNode *fastNode = head;
    while (fastNode != NULL && fastNode->next != NULL)
    {
        slowNode = slowNode->next;
        fastNode = fastNode->next->next;
        if (slowNode == fastNode)
        {
            ListNode *slowNode2 = head;
            while (slowNode != slowNode2)
            {
                slowNode = slowNode->next;
                slowNode2 = slowNode2->next;
            }
            return slowNode;
        }
    }
    return NULL;
}
/*
3
1 2 3
*/
int main()
{
    ListNode *head = nullptr;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        insertNodeFirst(&head, val);
    }
    reverseNode(&head);
    printAll(head);
    return 0;
}