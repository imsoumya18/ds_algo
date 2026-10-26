// @author Soumya
#include <iostream>
using namespace std;

// doubly linked list implementation
class node
{
public:
    int data;
    node *prev;
    node *next;

    node(int val)
    {
        data = val;
        prev = NULL;
        next = NULL;
    }
};

// insert node at head
// Time: O(1) | Space: O(1)
void insertAtHead(node *&head, int val)
{
    node *n = new node(val);

    n->next = head;
    if (head != NULL)
        head->prev = n;

    head = n;
}

// insert node at end
// Time: O(n) (walks to the tail) | Space: O(1)
void insertAtEnd(node *&head, int val)
{
    node *n = new node(val);

    if (head == NULL)
    {
        head = n;
        return;
    }

    node *temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = n;
    n->prev = temp;
}

// delete first node with given value
// Time: O(n) | Space: O(1)
void deleteNode(node *&head, int val)
{
    node *temp = head;

    while (temp != NULL && temp->data != val)
        temp = temp->next;

    if (temp == NULL)
        return;

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    delete temp;
}

// print elements forward (head to tail)
// Time: O(n) | Space: O(1)
void display(node *head)
{
    node *temp = head;

    cout << "NULL";
    while (temp != NULL)
    {
        cout << "<->" << temp->data;
        temp = temp->next;
    }
    cout << "<->NULL" << endl;
}

// print elements backward (tail to head)
// Time: O(n) | Space: O(1)
void displayReverse(node *head)
{
    if (head == NULL)
    {
        cout << "NULL" << endl;
        return;
    }

    node *temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    cout << "NULL";
    while (temp != NULL)
    {
        cout << "<->" << temp->data;
        temp = temp->prev;
    }
    cout << "<->NULL" << endl;
}

int main()
{
    node *head = NULL;
    insertAtEnd(head, 1);
    insertAtEnd(head, 2);
    insertAtEnd(head, 3);
    insertAtEnd(head, 4);
    insertAtHead(head, 0);
    /* resulting list:
       NULL <-> 0 <-> 1 <-> 2 <-> 3 <-> 4 <-> NULL
    */

    display(head);
    displayReverse(head);

    deleteNode(head, 0); // head
    deleteNode(head, 4); // tail
    deleteNode(head, 2); // middle
    display(head);

    return 0;
}
