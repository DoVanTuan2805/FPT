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
ListNode *insertSorted(ListNode *sorted, ListNode *insert)
{
    if (sorted == NULL || (sorted->val > insert->val))
    {
        insert->next = sorted;
        sorted = insert;
        return sorted;
    }
    else
    {
        ListNode *temp = sorted;
        while (temp->next != NULL && (temp->next->val <= insert->val))
            temp = temp->next;
        insert->next = temp->next;
        temp->next = insert;
    }
    return sorted;
}
ListNode *insertionSortList(ListNode *head)
{
    ListNode *listSorted = NULL;
    ListNode *curr = head;
    while (curr != NULL)
    {
        ListNode *nextNode = curr->next;
        listSorted = insertSorted(listSorted, curr);
        curr = nextNode;
    }
    return listSorted;
}
/*
Sort list using vector
*/
ListNode *sortListUsingVector(ListNode *head)
{
    vector<int> v;
    while (head != NULL)
    {
        v.push_back(head->val);
        head = head->next;
    }
    sort(v.begin(), v.end());
    ListNode *temp = new ListNode(0);
    ListNode *temp1 = NULL;
    for (int i = v.size() - 1; i >= 0; i--)
    {
        temp = new ListNode(v[i]);
        temp->next = temp1;
        temp1 = temp;
    }
    return temp1;
}
/*
4
4 2 1 3

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

    ListNode *sorted = insertionSortList(head);
    cout << "Linked List After Sorted : ";
    printAll(sorted);
    return 0;
}