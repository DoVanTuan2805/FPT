#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode()
    {
        this->val = 0;
        this->next = NULL;
    }
    ListNode(int val)
    {
        this->val = val;
        this->next = NULL;
    }
    ListNode(int val, ListNode *nextNode)
    {
        this->val = val;
        this->next = nextNode;
    }
};
void printAll(ListNode *head)
{
    while (head != nullptr)
    {
        cout << " " << head->val;
        head = head->next;
    }
    cout << endl;
}
void reverseNode(ListNode **head)
{
    ListNode *curr = *head;
    ListNode *prev = NULL;
    while (curr != NULL)
    {
        ListNode *temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    *head = prev;
}
ListNode *oddEvenList(ListNode *head)
{
    if (head == NULL)
        return head;
    ListNode *curr = head;
    int i = 0;
    ListNode *list = new ListNode(-1);
    ListNode *listTemp = list;
    ListNode *prev = NULL;
    while (curr != NULL)
    {
        i++;
        ListNode *nextNode = curr->next;
        if (i % 2 == 0)
        {
            listTemp->next = curr;
            listTemp = listTemp->next;
            if (curr->next != NULL)
            {
                prev->next = curr->next;
                prev = nextNode;
            }
        }
        else
        {
            prev = curr;
        }
        curr = nextNode;
    }
    // cout << "here";
    // printAll(prev);
    // printAll(list);
    prev->next = list->next;
    listTemp->next = NULL;
    return head;
}
/*
4
4 2 1 3

8
1 2 3 4 5 6 7 8

7
1 2 3 4 5 6 7
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
        head = new ListNode(val, head);
    }
    reverseNode(&head);
    cout << "Linked List : ";
    printAll(head);

    ListNode *oddEven = oddEvenList(head);
    cout << "Linked List After Odd Even Linked List : ";
    printAll(oddEven);
    return 0;
}