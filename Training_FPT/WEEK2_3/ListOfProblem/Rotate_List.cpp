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
int lengthNode(ListNode *head)
{
    int result = 0;
    while (head != nullptr)
    {
        result++;
        head = head->next;
    }
    return result;
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
ListNode *rotateRight(ListNode *head, int k)
{
    if (head == nullptr)
        return head;
    if (lengthNode(head) == 1)
        return head;
    int t = 0;
    if (k > 10)
    {
        while (k != 0)
        {
            t = k % 10;
            if (t != 0)
            {
                t = (k / 10) * 10 + t;
                break;
            }
            k = k / 10;
        }
    }
    else
    {
        t = k;
    }
    ListNode *curr = head;
    ListNode *prev = NULL;
    ListNode *subFirtNode = createNode(-1);
    subFirtNode->next = head;
    cout << t << endl;
    for (int i = 0; i < t; i++)
    {
        while (curr != NULL)
        {
            if (curr->next == NULL)
            {
                curr->next = subFirtNode->next;
                prev->next = nullptr;
                subFirtNode->next = curr;
                break;
            }
            prev = curr;
            curr = curr->next;
        }
    }
    return curr;
    // printAll(curr);
}
/*
3 1
0 1 2

5 2
1 2 3 4 5

3 2000000000
1 2 3

3 20
1 2 3

3 3
1 2 3

3 231
1 2 3
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
    cout << "Linked List :";
    printAll(head);
    // cout << lengthNode(head);
    ListNode *rRotation = rotateRight(head, k);
    printAll(rRotation);
    return 0;
}