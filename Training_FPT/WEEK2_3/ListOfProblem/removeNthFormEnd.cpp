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
    while (head != NULL)
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

ListNode *removeNthFromEnd(ListNode *head, int n)
{
    ListNode *temp = head;
    int pos = lengthNode(head) - n;
    // cout << pos << endl;
    if (pos == 0)
    {
        head = head->next;
        return head;
    }
    int i = 0;
    while (temp != NULL)
    {
        i++;
        if (pos == i)
        {
            temp->next = temp->next->next;
            break;
        }

        temp = temp->next;
    }
    return head;
}
/*
5 2
1 2 3 4 5

1 1
1
*/
int main()
{
    ListNode *head = nullptr;
    int num1 = 0, n, val;
    cin >> num1 >> n;
    for (int i = 0; i < num1; i++)
    {
        cin >> val;
        insertNodeFirst(&head, val);
    }
    reverseNode(&head);
    cout << "Linked list: ";
    printAll(head);

    ListNode *rHeadRemove = removeNthFromEnd(head, n);
    cout << "Linked list remove Nth " << n << ": ";
    printAll(rHeadRemove);
    return 0;
}