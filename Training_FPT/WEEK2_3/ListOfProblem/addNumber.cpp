/*
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.

Input: l1 = [0], l2 = [0]
Output: [0]

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
*/
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
void printAll(ListNode *head)
{
    while (head != NULL)
    {
        cout << " " << head->val;
        head = head->next;
    }
    cout << endl;
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
unsigned long long VectoInt(vector<int> vec)
{
    unsigned long long result = 0;
    for (auto i : vec)
    {
        result = result * 10 + i;
        // cout << " " << i;
    }
    // cout << endl;
    return result;
}
vector<int> IntToVec(unsigned long long num)
{
    vector<int> vec;
    if (num != 0)
    {
        while (num != 0)
        {
            vec.push_back(num % 10);
            num = num / 10;
        }
        return vec;
    }
    else
    {
        vec.push_back(num);
        return vec;
    }
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

ListNode *addTwoNumbers(ListNode *head1, ListNode *head2)
{
    ListNode *dummy = createNode(-1);
    ListNode *temp = dummy;
    int sum = 0;
    int carry = 0;

    if (lengthNode(head1) < lengthNode(head2))
    {
        swap(head1, head2);
    }
    while (head1 != nullptr || head1 != nullptr || sum != 0)
    {
        if (head1 != nullptr)
        {
            sum += head1->val;
            head1 = head1->next;
        }
        if (head2 != nullptr)
        {
            sum += head2->val;
            head2 = head2->next;
        }
        if (sum >= 10)
        {
            carry = sum / 10;
        }
        ListNode *newNode = createNode(sum % 10);
        temp->next = newNode;
        temp = temp->next;
        sum = 0;
        sum += carry;
        carry = 0;
    }
    return dummy->next;
}
/*
3 3
2 4 3
5 6 4

7 7
9 9 9 9 9 9 9
9 9 9 9 0 0 0

7 4
9 9 9 9 9 9 9
9 9 9 9

31 3
1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1
5 6 4

1 2
0
7 3
*/
int main()
{
    ListNode *head1 = nullptr;
    ListNode *head2 = nullptr;
    int num1 = 0, num2 = 0, val;
    cin >> num1 >> num2;

    for (int i = 0; i < num1; i++)
    {
        cin >> val;
        insertNodeFirst(&head1, val);
    }
    for (int i = 0; i < num2; i++)
    {
        cin >> val;
        insertNodeFirst(&head2, val);
    }
    reverseNode(&head1);
    reverseNode(&head2);

    cout << "Linked list 1: ";
    printAll(head1);
    cout << "Linked list 2: ";
    printAll(head2);
    ListNode *result = addTwoNumbers(head1, head2);
    cout << "Linked list after Add : ";
    printAll(result);
    return 0;
}