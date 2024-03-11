#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode()
    {
        this->val = 0;
        this->left = NULL;
        this->right = NULL;
    }
    TreeNode(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
    TreeNode(int val, TreeNode *left, TreeNode *right)
    {
        this->val = val;
        this->left = left;
        this->right = right;
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
void printAllTree(TreeNode *tree)
{
    if (tree == NULL)
    {
        // cout << endl;
        return;
    }
    cout << tree->val << " ";
    printAllTree(tree->left);
    printAllTree(tree->right);
}
TreeNode *insertTree(TreeNode *tree, int data)
{
    if (tree == NULL)
    {
        tree = new TreeNode(data);
        return tree;
    }
    else
    {
        TreeNode *curr;
        if (data <= tree->val)
        {
            curr = insertTree(tree->left, data);
            tree->left = curr;
        }
        else
        {
            curr = insertTree(tree->right, data);
            tree->right = curr;
        }
        return tree;
    }
}
void flatten(TreeNode *root)
{
    // Base case: if the current node is null, return null
    if (root == NULL)
    {
        cout << "next";
        return;
    }
    stack<TreeNode *> st;
    st.push(root);
    // If the left subtree was flattened, merge it with the current node
    // If the right subtree was flattened, return its tail node
    // If neither subtree was flattened, return the current node as the tail node
    while (st.empty() != true)
    {
        TreeNode *curr = st.top();
        st.pop();
        if (curr == NULL)
            return;
        if (curr->right != NULL)
            st.push(curr->right); // Connect the right subtree of the left tail to the right subtree of the current node
        if (curr->left != NULL)
            st.push(curr->left); // Make the left subtree the new right subtree of the current node
        if (st.empty() != true)  // Set the left child of the current node to null
        {
            curr->right = st.top();
        }
        curr->left = NULL;
    }
    return;
}
/*
6
1 2 5 3 4 6
*/
int main()
{
    TreeNode *tree = NULL;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        tree = insertTree(tree, val);
    }
    // reverseNode(&head);
    cout << "Tree : ";
    printAllTree(tree);
    cout << "Flatten Tree : ";
    flatten(tree);
    printAllTree(tree);
    return 0;
}