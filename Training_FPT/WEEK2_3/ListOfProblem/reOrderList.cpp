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
void reorderList(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return;
    ListNode *dummy = new ListNode(-1);
    dummy->next = head;
    ListNode *prev = dummy;
    ListNode *curr = head;
    vector<int> vec;
    while (curr != NULL)
    {
        vec.push_back(curr->val);
        curr = curr->next;
    }
    int i = 0, j = vec.size() - 1;
    bool oddEven = false;
    while (i < j)
    {
        prev->next = new ListNode(vec.at(i));
        prev = prev->next;
        prev->next = new ListNode(vec.at(j));
        prev = prev->next;
        i++;
        j--;
    }
    if (vec.size() % 2 != 0)
    {
        prev->next = new ListNode(vec.at(i++));
        prev = prev->next;
    }
    prev->next = nullptr;
    *head = *dummy->next;
    // printAll(head);
}
/*
4
1 2 3 4

5
1 2 3 4 5
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
    reorderList(head);
    cout << "Linked List After ReOrder : ";
    printAll(head);
    return 0;
}