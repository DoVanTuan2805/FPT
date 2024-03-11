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
        ListNode *temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    *head = prev;
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

ListNode *swapPairs(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;
    ListNode *temp = head;
    while (temp != nullptr && temp->next != nullptr)
    {
        swap(temp->val, temp->next->val);
        temp = temp->next->next;
    }
    return head;
}
/*
4
1 2 3 4
*/
int main()
{
    ListNode *head = nullptr;
    int num1 = 0, n, val;
    cin >> num1;
    for (int i = 0; i < num1; i++)
    {
        cin >> val;
        insertNodeFirst(&head, val);
    }
    reverseNode(&head);
    cout << "Linked list: ";
    printAll(head);
    // cout << head << endl;
    // cout << head->next << endl;
    // cout << head->next->next << endl;
    // cout << head->next->next->next << endl;

    ListNode *swapPair = swapPairs(head);
    printAll(swapPair);
    return 0;
}