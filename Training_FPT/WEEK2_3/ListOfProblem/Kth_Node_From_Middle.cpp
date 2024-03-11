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
int lenthNode(ListNode *head)
{
    int result = 0;
    while (head != NULL)
    {
        result++;
        head = head->next;
    }
    return result;
}
int solve(ListNode *A, int B)
{
    int mid = 0;
    int length = lenthNode(A);
    // cout << "Length :" << length;
    if (round(length / 2) >= B)
    {
        mid = length / 2 + 1;
    }
    if (length < B)
    {
        return -1;
    }
    if (length <= 2)
    {
        mid = length;
    }
    int pos = mid - B;
    // cout << "Pos : " << pos;
    ListNode *curr = A;
    while (--pos)
    {
        curr = curr->next;
    }
    return curr->val;
}
/*
10 5
3 4 7 5 6 16 15 61 16 17

9 2
3 4 7 5 6 16 15 61 16

2 1
468 335
*/
int main()
{
    ListNode *head = nullptr;
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        insertNodeFirst(&head, val);
    }
    reverseNode(&head);
    cout << "Linked List : ";
    printAll(head);
    int out = solve(head, k);
    cout << "Solve : " << out;
    return 0;
}
