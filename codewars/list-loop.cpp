#include <gtest/gtest.h>

struct Node
{
    Node *next;
    Node *getNext()
    {
        return next;
    }
    void setNext(Node *n)
    {
        next = n;
    }
};

int count(Node *n)
{
    int r = 1;
    Node *t = n;
    while (t->getNext() != n)
    {
        ++r;
        t = t->getNext();
    }
    return r;
}

int getLoopSize(Node *startNode)
{
    Node *slow = startNode;
    Node *fast = startNode;
    while (slow && fast && fast->getNext())
    {
        slow = slow->getNext();
        fast = fast->getNext()->getNext();
        if (slow == fast)
        {
            return count(slow);
        }
    }
    return 0;
}

TEST(ListLoop, example)
{
    Node n1, n2, n3, n4;

    n1.setNext(&n2);
    n2.setNext(&n3);
    n3.setNext(&n4);
    n4.setNext(&n2);

    int actual = getLoopSize(&n1);
    EXPECT_EQ(actual, 3);
}