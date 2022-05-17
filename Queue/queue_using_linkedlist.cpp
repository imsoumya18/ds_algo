// @author Soumya
#include <iostream>
using namespace std;

#define n 20

class node
{
public:
    int data;
    node *next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};

class queue
{
    node *front;
    node *back;

public:
    queue()
    {
        front = NULL;
        back = NULL;
    }

    void enqueue(int x)
    {
        node *nd = new node(x);
        if (front == NULL)
        {
            front = nd;
            back = nd;
            return;
        }
        back->next = nd;
        back = nd;
    }

    void dequeue()
    {
        if (front == NULL)
        {
            cout << "Queue underflow!!" << endl;
            return;
        }

        node *todelete = front;
        front = front->next;

        delete todelete;
    }

    int peek()
    {
        if (front == NULL)
        {
            cout << "NO element in queue!!" << endl;
            return -1;
        }

        return front->data;
    }

    bool empty()
    {
        if (front == NULL)
            return true;
        return false;
    }
};

int main()
{
    queue q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);

    cout << q.peek() << endl;
    q.dequeue();

    cout << q.peek() << endl;
    q.dequeue();

    cout << q.peek() << endl;
    q.dequeue();

    cout << q.peek() << endl;
    q.dequeue();

    cout << q.peek() << endl;
    q.dequeue();

    cout << q.empty() << endl;

    return 0;
}
