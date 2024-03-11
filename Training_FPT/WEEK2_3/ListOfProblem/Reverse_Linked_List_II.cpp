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
void printAll(ListNode *head)
{
    while (head != NULL)
    {
        cout << " " << head->val;
        head = head->next;
    }
    cout << endl;
}
void reverseNode(ListNode **head)
{
    ListNode *curr = *head;
    ListNode *prev = nullptr;
    while (curr != nullptr)
    {
        ListNode *temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    *head = prev;
}
ListNode *reverseBetween(ListNode *head, int left, int right)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    ListNode *dummy = createNode(-1);
    dummy->next = head;
    ListNode *prevLeftNode = dummy;
    ListNode *currNode = head;

    for (int i = 0; i < left - 1; i++)
    {
        prevLeftNode = prevLeftNode->next;
        currNode = currNode->next;
    }
    ListNode *subLeftNode = currNode;
    ListNode *prevNode = nullptr;
    // cout << "List Curr Node : ";
    // printAll(currNode);
    for (int i = 0; i <= right - left; i++)
    {
        ListNode *nextNode = currNode->next;
        currNode->next = prevNode;
        prevNode = currNode;
        currNode = nextNode;
    }
    prevLeftNode->next = prevNode;
    subLeftNode->next = currNode;

    cout << "List Add : ";
    printAll(dummy->next);
}
/*
5 2 4
1 2 3 4 5
*/
int main()
{
    ListNode *head = nullptr;
    int n, left, right;
    cin >> n >> left >> right;
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        insertNodeFirst(&head, val);
    }
    reverseNode(&head);
    cout << "Linked list: ";
    printAll(head);
    reverseBetween(head, left, right);
    return 0;
}