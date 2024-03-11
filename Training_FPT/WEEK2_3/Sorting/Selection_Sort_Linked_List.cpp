#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int data;
    ListNode *next;
    ListNode()
    {
        this->data = 0;
        this->next = NULL;
    }
    ListNode(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    ListNode(int data, ListNode *head)
    {
        this->data = data;
        this->next = head;
    }
};
void reveseNode(ListNode **head)
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
void display(ListNode *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
ListNode *sort(ListNode *prev, ListNode *current)
{
    ListNode *temp = NULL;
    while (current != NULL)
    {
        if (current->data < prev->data)
        {
            temp = current;
        }
        current = current->next;
    }
    return temp;
}
ListNode *selectionSort(ListNode *head)
{
    ListNode *curr = head;
    ListNode *min = NULL;
    ListNode *temp = NULL;
    while (curr != NULL)
    {
        min = curr;
        ListNode *nextNode = curr->next;
        temp = sort(min, curr->next);
        if (temp != NULL)
        {
            if (temp != min)
            {
                swap(temp->data, min->data);
            }
        }
        curr = curr->next;
    }
    return head;
}
/*
5
3 2 5 1 7
*/
int main()
{
    ListNode *head = NULL;
    int n;
    cin >> n;
    while (n--)
    {
        int val;
        cin >> val;
        head = new ListNode(val, head);
    }
    reveseNode(&head);
    ListNode *sort = selectionSort(head);
    display(sort);
    return 0;
}