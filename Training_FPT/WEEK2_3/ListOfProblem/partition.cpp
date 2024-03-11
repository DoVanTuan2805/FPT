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
ListNode *partition(ListNode *head, int x)
{
    ListNode *curr = head;
    ListNode *dummy1 = new ListNode(-1);
    ListNode *dummy2 = new ListNode(-1);
    ListNode *list1 = dummy1;
    ListNode *list2 = dummy2;
    while (curr != NULL)
    {
        if (curr->val < x)
        {
            list2->next = curr;
            list2 = list2->next;
        }
        else
        {
            list1->next = curr;
            list1 = list1->next;
        }
        curr = curr->next;
    }
    list1->next = NULL;
    list2->next = dummy1->next;
    // printAll(dummy1->next);
    //  printAll(dummy2->next);
    return dummy2->next;
}

/*
6 3
1 4 3 2 5 2
*/
int main()
{
    ListNode *head = NULL;
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        head = new ListNode(val, head);
    }
    reverseNode(&head);
    cout << "Linked List : ";
    printAll(head);

    ListNode *rPartition = partition(head, k);
    printAll(rPartition);
    return 0;
}