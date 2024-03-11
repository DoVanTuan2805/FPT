#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *nodeLeft;
    TreeNode *nodeRight;
    TreeNode()
    {
        this->val = 0;
        this->nodeLeft = nullptr;
        this->nodeRight = nullptr;
    }
    TreeNode(int val)
    {
        this->val = val;
        this->nodeLeft = nullptr;
        this->nodeRight = nullptr;
    }
    TreeNode(int val, TreeNode *left, TreeNode *right)
    {
        this->val = 0;
        this->nodeLeft = left;
        this->nodeRight = right;
    }
    void printAllTree(TreeNode *tree)
    {
        if (tree == NULL)
            return;
        cout << " " << tree->val;
        printAllTree(tree->nodeLeft);
        printAllTree(tree->nodeRight);
    }
};

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
    void printAll(ListNode *head)
    {
        while (head != nullptr)
        {
            cout << " " << head->val;
            head = head->next;
        }
        cout << endl;
    }
};

void reverseNode(ListNode **head)
{
    ListNode *curr = *head;
    ListNode *prev = nullptr;
    while (curr != nullptr)
    {
        ListNode *nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    *head = prev;
}
void printAll(ListNode *head)
{
    while (head != nullptr)
    {
        cout << " " << head->val;
        head = head->next;
    }
    cout << endl;
}
void printAllTree(TreeNode *tree)
{
    if (tree == NULL)
        return;
    cout << " " << tree->val;
    printAllTree(tree->nodeLeft);
    printAllTree(tree->nodeRight);
}
vector<int> vec; // array save data
TreeNode *TreeRecur(int beginVec, int endVec)
{
    if (endVec < beginVec)
        return NULL;
    int mid = (endVec + beginVec) / 2;
    TreeNode *tree = new TreeNode();
    tree->val = vec.at(mid);
    tree->nodeLeft = TreeRecur(beginVec, mid - 1);
    tree->nodeRight = TreeRecur(mid + 1, endVec);
    return tree;
}
TreeNode *ListToTree(ListNode *head)
{
    while (head != nullptr)
    {
        vec.push_back(head->val);
        head = head->next;
    }
    int length = vec.size() - 1;
    return TreeRecur(0, length);
}

/*
5
-10 -3 0 5 9

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
    cout << "Linked List: ";
    printAll(head);
    TreeNode *BinaryTree = ListToTree(head);
    printAllTree(BinaryTree);
    return 0;
}