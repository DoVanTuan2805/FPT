#include <bits/stdc++.h>
using namespace std;
class MyCircularDeque
{
public:
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
    };
    ListNode *font;
    ListNode *rear;
    int capacity = 0, size = 0;
    MyCircularDeque(int k)
    {
        capacity = k;
        font = rear = NULL;
    }

    bool insertFront(int value)
    {
        if (isFull())
            return false;
        size++;
        ListNode *newNode = new ListNode(value);
        if (font == NULL || rear == NULL)
        {
            font = rear = newNode;
            return true;
        }
        newNode->next = font;
        font = newNode;
        return true;
    }

    bool insertLast(int value)
    {
        if (isFull())
            return false;
        size++;
        ListNode *newNode = new ListNode(value);
        if (font == NULL || rear == NULL)
        {
            font = rear = newNode;
            return true;
        }
        rear->next = newNode;
        rear = newNode;
        return true;
    }

    bool deleteFront()
    {
        if (isEmpty())
            return false;
        size--;
        font = font->next;
        return true;
    }

    bool deleteLast()
    {
        if (rear == NULL)
        {
            return false;
        }
        size--;
        ListNode *curr = font;
        ListNode *prev = NULL;
        while (curr != NULL)
        {
            if (curr == rear)
            {
                break;
            }
            prev = curr;
            curr = curr->next;
        }
        rear = prev;
        return true;
    }

    int getFront()
    {
        if (isEmpty())
            return -1;
        return font->val;
    }

    int getRear()
    {
        if (isEmpty())
            return -1;
        return rear->val;
    }

    bool isEmpty()
    {
        if (font == NULL)
            return true;
        if (size == 0)
            return true;
        return false;
    }

    bool isFull() { return size == capacity; }
    void printAll()
    {
        ListNode *curr = font;
        cout << endl;
        while (curr != NULL)
        {
            cout << curr->val << " ";
            if (curr == rear)
                break;
            curr = curr->next;
        }
    }
};
int main()
{
    int k = 5;
    MyCircularDeque *obj = new MyCircularDeque(k);
    vector<string> cmd = {
        "MyCircularDeque", "insertFront", "deleteLast", "isFull", "insertFront", "isFull", "deleteFront", "deleteFront", "deleteLast", "isEmpty", "insertLast", "deleteLast", "deleteFront", "insertLast", "getRear", "getRear", "deleteLast", "deleteFront", "insertFront", "deleteLast", "getFront", "getRear", "getRear", "getFront", "insertLast", "getFront", "isEmpty", "getFront", "insertFront", "insertFront", "getRear", "insertFront", "insertLast", "deleteFront", "getRear", "deleteLast", "deleteFront", "insertFront", "getRear", "insertLast", "insertLast", "getRear", "getFront", "insertLast", "isFull", "deleteFront", "insertFront", "getFront", "getFront", "getFront", "isEmpty", "insertLast", "insertLast", "getRear", "getRear", "getRear", "getFront", "getFront", "getFront", "isEmpty", "deleteLast", "deleteFront", "deleteFront", "getFront", "insertLast", "getFront", "getFront", "deleteLast", "insertFront", "insertFront", "deleteLast", "insertFront", "isFull", "getRear", "isFull", "isFull", "getRear", "getFront", "getFront", "insertFront", "getFront", "deleteFront", "insertFront", "getRear", "insertFront", "insertLast", "insertFront", "getFront", "insertFront", "insertLast", "insertLast", "getFront", "insertFront", "deleteLast", "insertFront", "insertFront", "insertFront", "insertFront", "getFront", "insertLast", "getFront", "deleteLast"};
    // 6 6 9 5
    vector<int> value =
        {
            84, 60, NULL, NULL, 80, NULL, NULL, NULL, NULL, NULL, 29, NULL, NULL, 6, NULL, NULL, NULL, NULL, 12, NULL, NULL, NULL, NULL, NULL, 85, NULL, NULL, NULL, 54, 7, NULL, 42, 37, NULL, NULL, NULL, NULL, 54, NULL, 8, 87, NULL, NULL, 49, NULL, NULL, 77, NULL, NULL, NULL, NULL, 57, 44, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 51, NULL, NULL, NULL, 74, 76, NULL, 4, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 61, NULL, NULL, 82, NULL, 11, 74, 85, NULL, 5, 7, 6, NULL, 98, NULL, 88, 93, 50, 35, NULL, 3, NULL, NULL};

    for (int i = 0; i < cmd.size(); i++)
    {
        if (cmd.at(i) == "insertFront")
        {
            obj->insertFront(value.at(i));
        }
        else if (cmd.at(i) == "insertLast")
        {
            obj->insertLast(value.at(i));
        }
        else if (cmd.at(i) == "deleteLast")
        {
            obj->deleteLast();
        }
        else if (cmd.at(i) == "deleteFront")
        {
            obj->deleteFront();
        }
        else if (cmd.at(i) == "getFront")
        {
            cout << "Get Font :" << obj->getFront() << endl;
        }
        else if (cmd.at(i) == "getRear")
        {
            cout << "Get Rear :" << obj->getRear() << endl;
        }
        else if (cmd.at(i) == "isEmpty")
        {
            cout << obj->isEmpty() ? "true" : "false";
            cout << endl;
        }
        else if (cmd.at(i) == "isFull")
        {
            cout << obj->isFull() ? "true" : "false";
            cout << endl;
        }
    }

    obj->printAll();
    // 9
    //   9 7 0 3

    return 0;
}
