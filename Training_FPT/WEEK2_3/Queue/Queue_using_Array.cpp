#include <bits/stdc++.h>
using namespace std;

class Queue
{
public:
    int Font, Rear, size;
    uint16_t capacity;
    int *array;
};
Queue *createQueue(int capacity)
{
    Queue *queue = new Queue();
    queue->capacity = capacity;
    queue->Font = queue->size = 0;
    queue->Rear = queue->capacity - 1;
    queue->array = (int *)malloc(queue->capacity * sizeof(int));
    return queue;
}
bool isFull(Queue *queue)
{
    if (queue->size == queue->capacity)
        return true;
    return false;
}
bool isEmpty(Queue *queue)
{
    if (queue->size == 0)
        return true;
    return false;
}
void enQueue(Queue *queue, int val)
{
    queue->Rear = (queue->Rear + 1) % queue->capacity; // 0 1 2 3 4 5 ...
    queue->array[queue->Rear] = val;
    queue->size = queue->size + 1;
    cout << "EnQueue : " << val << endl;
}
int deQueue(Queue *queue)
{
    if (isEmpty(queue))
        exit(1);
    int val = queue->array[queue->Font];
    queue->Font = (queue->Font + 1) % queue->capacity;
    queue->size = queue->size - 1;
    return val;
}
int isFont(Queue *queue)
{
    if (isEmpty(queue))
        exit(1);
    return queue->array[queue->Font];
}
int isRear(Queue *queue)
{
    if (isEmpty(queue))
        exit(1);
    return queue->array[queue->Rear];
}
int main()
{
    Queue *queue = createQueue(100);
    enQueue(queue, 10);
    cout << "Is Font : " << isFont(queue) << endl;
    cout << "DeQueue : " << deQueue(queue) << endl;
    return 0;
}