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

ListNode *mergeTwoListSorted(ListNode *list1, ListNode *list2)
{
    if (list1 == NULL)
        return list2;
    if (list2 == NULL)
        return list1;

    ListNode *dummy = new ListNode(-1);
    ListNode *prev = dummy;
    while (list1 != NULL && list2 != NULL)
    {
        if (list1->val < list2->val)
        {
            prev->next = list1;
            list1 = list1->next;
        }
        else
        {
            prev->next = list2;
            list2 = list2->next;
        }
        prev = prev->next;
    }
    if (list1 != NULL)
    {
        prev->next = list1;
    }
    if (list2 != NULL)
    {
        prev->next = list2;
    }
    return dummy->next;
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
/*
3 3
4 2 1
4 3 1
 */
int main()
{

    ListNode *head1 = nullptr;
    ListNode *head2 = nullptr;
    int num1 = 0, num2 = 0, val;
    // cin >> num >> valDelete;
    cin >> num1 >> num2;
    for (int i = 0; i < num1; i++)
    {
        cin >> val;
        head1 = new ListNode(val, head1);
    }
    for (int i = 0; i < num2; i++)
    {
        cin >> val;
        head2 = new ListNode(val, head2);
    }
    cout << "Linked List 1 :";
    printAll(head1);
    cout << "Linked List 2 :";
    printAll(head2);

    ListNode *mergeNode = mergeTwoListSorted(head1, head2);
    cout << "Linked List Merge : ";
    printAll(mergeNode);
    return 0;
}