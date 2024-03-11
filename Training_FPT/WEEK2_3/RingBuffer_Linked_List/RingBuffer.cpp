#include <bits/stdc++.h>
using namespace std;

class RingBuffer
{
private:
    struct ListNode
    {
        int val;
        ListNode *next;
    };
    /* data */
public:
    ListNode *font;
    ListNode *rear;
    RingBuffer();
    ~RingBuffer();
};

RingBuffer::RingBuffer()
{
}

RingBuffer::~RingBuffer()
{
}
