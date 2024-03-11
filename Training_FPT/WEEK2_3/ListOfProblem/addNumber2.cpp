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
    ListNode(int val, ListNode *head)
    {
        this->val = val;
        this->next = head;
    }
};

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
    ListNode *dummy = new ListNode(-1);
    ListNode *temp = dummy;
    int sum = 0;
    int carry = 0;
    reverseNode(&head1);
    reverseNode(&head2);
    printAll(head1);
    printAll(head2);
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
        ListNode *newNode = new ListNode(sum % 10);
        temp->next = newNode;
        temp = temp->next;
        sum = 0;
        sum += carry;
        carry = 0;
    }
    reverseNode(&dummy->next);
    return dummy->next;
}
/*
4 3
7 2 4 3
5 6 4
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
        head1 = new ListNode(val, head1);
    }
    for (int i = 0; i < num2; i++)
    {
        cin >> val;
        head2 = new ListNode(val, head2);
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