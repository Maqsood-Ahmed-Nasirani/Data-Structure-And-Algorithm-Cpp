#include <iostream>
using namespace std;

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

void insertAtHead(node *&head, int val)
{
    node *n = new node(val);
    n->next = head;
    head = n;
}

void insertAtTail(node *&head, int val)
{
    node *n = new node(val);

    if (head == NULL)
    {
        head = n;
        return;
    }

    node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}

void display(node *head)
{
    node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << "-> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

bool search(node *head, int key)
{
    node *temp = head;

    while (temp != NULL)
    {
        if (temp->data == key)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void deleteAtHead(node *&head)
{
    node *todelete = head;
    head = head->next;
    delete todelete;
}

void deletion(node *&head, int val)
{
    if (head == NULL)
        return;

    if (head->next == NULL)
    {
        deleteAtHead(head);
        return;
    }

    node *temp = head;
    while (temp->next != NULL && temp->next->data != val)
    {
        temp = temp->next;
    }

    if (temp->next == NULL)
        return;

    node *todelete = temp->next;
    temp->next = temp->next->next;

    delete todelete;
}

node *reverseLinkedList(node *&head)
{
    node *prevptr = NULL;
    node *currptr = head;
    node *nextptr;

    while (currptr != NULL)
    {
        nextptr = currptr->next;
        currptr->next = prevptr;

        prevptr = currptr;
        currptr = nextptr;
    }

    return prevptr;
}

node *recursiveReverse(node *&head)
{
    if (head == NULL || head->next == NULL)
        return head;

    node *newhead = recursiveReverse(head->next);
    head->next->next = head;
    head->next = NULL;

    return newhead;
}

node *reverseKnodes(node *head, int k)
{
    node *prevptr = NULL;
    node *currptr = head;
    node *nextptr;

    int count = 0;
    while (currptr != NULL && count < k)
    {
        nextptr = currptr->next;
        currptr->next = prevptr;

        prevptr = currptr;
        currptr = nextptr;
        count++;
    }

    if (nextptr != NULL)
    {
        head->next = reverseKnodes(nextptr, k);
    }

    return prevptr;
}

int main(void)
{

    // node* head = NULL;
    // insertAtTail(head, 1);
    // insertAtTail(head, 4);
    // insertAtTail(head, 12);
    // insertAtTail(head, 71);
    // display(head);
    // // insertAtHead(head, 10);
    // // display(head);

    // // deletion(head, 12);
    // // display(head);

    // // deleteAtHead(head);
    // // display(head);

    // // node* newhead = reverseLinkedList(head);
    // // display(newhead);
    // node* n = recursiveReverse(head);
    // display(n);

    // cout << "Searching for 71: " << search(head, 71) << endl;

    node *h = NULL;
    insertAtTail(h, 1);
    insertAtTail(h, 2);
    insertAtTail(h, 3);
    insertAtTail(h, 4);
    insertAtTail(h, 5);
    insertAtTail(h, 6);

    display(h);
    int k = 2;
    node *nd = reverseKnodes(h, k);
    display(nd);

    return 0;
}
