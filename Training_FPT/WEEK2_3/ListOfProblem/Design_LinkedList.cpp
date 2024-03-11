#include <bits/stdc++.h>
using namespace std;
class MyLinkedList
{
public:
    struct LinkedList
    {
        int val;
        LinkedList *next;
        LinkedList()
        {
            this->val = 0;
            this->next = NULL;
        }
        LinkedList(int val)
        {
            this->val = val;
            this->next = NULL;
        }
        LinkedList(int val, LinkedList *next)
        {
            this->val = val;
            this->next = next;
        }
    };
    LinkedList *head;
    MyLinkedList() { head = NULL; }

    void removeNode(LinkedList *prev, LinkedList *curr)
    {
        prev->next = curr->next;
        curr = curr->next;
    }

    int get(int index)
    {
        int length = lengthList();
        if (index > length - 1)
            return -1;
        LinkedList *curr = head;
        while (index--)
        {
            curr = curr->next;
        }
        return curr->val;
    }

    void addAtHead(int val)
    {
        LinkedList *newNode = new LinkedList(val, head);
        head = newNode;
    }

    void addAtTail(int val)
    {
        if (head == NULL)
        {
            LinkedList *newNode = new LinkedList(val);
            newNode->next = head;
            head = newNode;
            return;
        }
        LinkedList *curr = head;
        while (curr->next != NULL)
        {
            // cout << curr->val << " ";
            curr = curr->next;
        }
        LinkedList *newNode = new LinkedList(val);
        curr->next = newNode;
        curr = newNode;
        return;
    }

    int lengthList()
    {
        if (head == NULL)
            return 0;
        LinkedList *curr = head;
        int result = 0;
        while (curr != NULL)
        {
            result++;
            curr = curr->next;
        }
        return result;
    }
    void addAtIndex(int index, int val)
    {
        if (index == 0)
        {
            LinkedList *newNode = new LinkedList(val);
            newNode->next = head;
            head = newNode;
            return;
        }
        int length = lengthList();
        if (index > length - 1)
            return;
        LinkedList *curr = head;
        LinkedList *prev = new LinkedList();
        while (index--)
        {
            prev = curr;
            curr = curr->next;
        }
        LinkedList *newNode = new LinkedList(val);
        newNode->next = curr;
        prev->next = newNode;
    }
    void deleteAtIndex(int index)
    {
        if (index > lengthList() - 1 || head == NULL)
        {
            return;
        }
        if (index == 0)
        {
            head = head->next;
            return;
        }
        LinkedList *curr = head;
        LinkedList *prev = NULL;

        while (index--)
        {
            // cout << "here";
            prev = curr;
            curr = curr->next;
        }
        removeNode(prev, curr);
    }
    void printAll()
    {
        LinkedList *curr = head;
        while (curr != NULL)
        {
            cout << curr->val << " ";
            curr = curr->next;
        }
        cout << endl;
    }
};
int main()
{
    MyLinkedList *obj = new MyLinkedList();
    // obj->addAtHead(1);
    // obj->addAtTail(3);
    // obj->addAtIndex(1, 2);
    // obj->printAll();
    // cout << "Get : " << obj->get(1) << endl;
    // // obj->printAll();
    // obj->deleteAtIndex(1);
    // obj->printAll();
    // cout << "Get : " << obj->get(1) << endl;

    // obj->addAtHead(1);
    // obj->addAtTail(3);
    // obj->addAtIndex(1, 2);
    // obj->printAll();
    // cout << "Get : " << obj->get(1) << endl;
    // obj->deleteAtIndex(2);
    // obj->printAll();
    // cout << "Get : " << obj->get(0) << endl;

    obj->addAtHead(2);
    obj->deleteAtIndex(1);
    obj->addAtHead(2);
    obj->addAtHead(7);
    obj->addAtHead(3);
    obj->addAtHead(2);
    obj->addAtHead(5);
    obj->addAtTail(5);
    cout << "Get : " << obj->get(5) << endl;
    obj->deleteAtIndex(6);
    obj->deleteAtIndex(5);
    obj->printAll();

    return 0;
}