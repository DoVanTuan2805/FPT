#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode()
    {
        this->val = 0;
        this->next = nullptr;
    }
    ListNode(int val)
    {
        this->val = val;
        this->next = nullptr;
    }
};
struct Queue
{
    ListNode *Font, *Rear;
    Queue()
    {
        Font = Rear = NULL;
    }
    void EnQueue(int val)
    {
        ListNode *temp = new ListNode(val);
        if (Rear == NULL)
        {
            Font = Rear = temp;
            return;
        }
        Rear->next = temp;
        Rear = temp;
    }
    bool isEmty()
    {
        return Font == NULL;
    }
    void DeQueue()
    {
        if (isEmty())
        {
            cout << "Queue is Emty";
            return;
        }
        if (Font == Rear)
            Font = Rear = NULL;
        else
            Font = Font->next;
    }
    int Peek()
    {
        if (isEmty())
        {
            cout << "Queue is Emty";
            exit(1);
        }
        return Font->val;
    }
};
int main()
{
    Queue *queue = new Queue();
    queue->EnQueue(10);
    // cout << queue->DeQueue();
    queue->EnQueue(11);
    queue->EnQueue(13);
    queue->DeQueue();
    queue->DeQueue();
    queue->DeQueue();
    cout << queue->Peek();
    return 0;
}
