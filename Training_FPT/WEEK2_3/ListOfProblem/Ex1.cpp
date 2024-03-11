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
void insertNodeEnd(ListNode **head, int val)
{
    ListNode *newNode = createNode(val);
    if (head == NULL) // neu chua co  node nao
    {
        *head = newNode;
        return;
    }
    ListNode *curr = *head;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = newNode;
    return;
}
ListNode *removeElements(ListNode *head, int val)
{
    if (head == nullptr)
    {
        return head;
    }
    ListNode *temp = (ListNode *)malloc(sizeof(ListNode));
    temp->next = head;
    ListNode *current = temp;
    while (current->next != NULL)
    {
        cout << "Val :" << current->next->val << endl;
        if (current->next->val == val)
        {
            current->next = current->next->next;
        }
        else
        {
            current = current->next;
        }
    }
    return temp->next;
}
ListNode *reverseElements(ListNode *head)
{
    ListNode *curr = head;
    ListNode *prev = nullptr;
    while (curr != nullptr)
    {
        ListNode *temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}
ListNode *removeDuplicates(ListNode *head)
{
    ListNode *curr = head;
    ListNode *prev = nullptr;
    while (curr != nullptr)
    {

        if (prev != nullptr && curr->val == prev->val)
        {
            prev->next = curr->next;
            curr = curr->next;
        }
        else
        {
            prev = curr;
            curr = curr->next;
        }
        // cout << "curr->val :" << curr->val << endl;
    }
    return head;
}
ListNode *mergeTwoListSorted(ListNode *list1, ListNode *list2)
{
    if (!list1)
        return list2;
    if (!list2)
        return list1;

    ListNode *dummy = createNode(-1);
    ListNode *prev = dummy;

    while (list1 != nullptr && list2 != nullptr)
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
}
bool Palindrome(ListNode *head)
{
    vector<int> vec;
    ListNode *curr = head;
    while (curr->next != NULL)
    {
        // cout << "curr->val :" << curr->val;
        vec.push_back(curr->val);
        curr = curr->next;
    }
    int i = 0;
    int j = vec.size() - 1;
    while (i < j)
    {
        if (vec.at(i) != vec.at(j))
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
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

int main()
{
    ListNode *head = nullptr;
    ListNode *head = nullptr;
    int num = 0, val, valDelete;
    // cin >> num >> valDelete;

    for (int i = 0; i < num; i++)
    {
        cin >> val;
        insertNodeFirst(&head, val);
    }
    cout << "Linked List :";
    printAll(head);

    // ListNode *rHead = removeElements(head, valDelete);
    // ListNode *rHeadReverse = reverseElements(head);
    // cout << "Linked List Reverse :";
    // printAll(rHeadReverse);

    ListNode *rHeadDup = removeDuplicates(head);
    cout << "Linked List Duplicates :";
    printAll(rHeadDup);

    if (Palindrome(head) == true)
    {
        cout << "Is Palindrome" << endl;
    }
    else
    {
        cout << "Is not Palindrome" << endl;
    }
    // printAll(head);
    return 0;
}