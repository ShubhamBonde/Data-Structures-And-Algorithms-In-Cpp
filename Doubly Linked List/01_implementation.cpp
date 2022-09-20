
// Implementation on my own.
#include<bits/stdc++.h>
using namespace std;

class Dll
{
    public:
        int data;
        Dll *next = NULL;
        Dll *prev = NULL;

        // void F_traverse(Dll *head);
};

void F_traverse(Dll *head)
{
    
    for(;head != NULL; head = head->next)
    {
        cout << head->data << " ";
    }
    cout << endl;
}

void R_traverse(Dll *tail)
{
    for(;tail != NULL; tail = tail->prev)
    {
        cout << tail->data << " ";
    }

    cout << endl;
}

void insertAtHead(Dll *&head, Dll *&tail, int data)
{

    
    Dll * temp = new Dll;
    if (head == NULL)
    {
        temp->next = NULL;
        temp ->prev = NULL;
        tail = temp;
    }
    else
    {
        head->prev = temp;
        temp->next = head;
    }
    temp-> data = data;
    head = temp;
    
}


void insertAtTail(Dll *&head, Dll *&tail, int data)
{
    Dll * temp = new Dll;
    temp->data = data;
    
    if (head == NULL)
    {
        head = temp;
        tail = temp;

    }
    else
    {
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
    
}

void insertAfter(Dll *&head, int position ,int data)
{
    Dll *node = new Dll;
    if (!node)
    {
        cout << "Memory Error\n";
        return;
    }

    node->data = data;
    if (head == NULL)
    {
        head = node;
        return;
    }
    
    if (position == 1)
    {
        node->next = head;
        head->prev = node;
        head = node;
        return;
    }

    Dll *temp = head;
    int i = 0;
    for(;i < position-1 && temp->next != NULL; i++, temp = temp->next);
    /* 
        Why they did i < position-1?
        Because if you do i < position then the incrementor will still increment
        temp to temp->next and thereafter the position you'll be inserting after
        will be the next position of the position you want to insert after.
        That's why position-1.
    */
    if (i+1 < position)
    {
        cout << "Position does not exist\n";
        return; 
    }

    node->prev = temp;
    node->next = temp->next;
    temp->next->prev = node;
    temp->next = node;
    return;



}


int listSize(Dll *head)
{
    int size = 0;
    for(;head != NULL; head = head->next, size++);
    return size;
}

int main()
{
    Dll *head = NULL;
    Dll *tail = NULL;

    // // Objects
    // Dll node1;
    // Dll node2;

    // head = &node1;
    // node1.data = 10;
    // node1.next = &node2;
    // node1.prev = NULL;

    // node2.data = 20;
    // node2.next = NULL;
    // node2.prev = &node1;
    // tail = &node2;

     

    // F_traverse(head);
    // R_traverse(tail);
    // works

    for(int i = 10; i <= 100; i+= 10)
    {
        insertAtTail(head, tail, i);
    }

    cout << "list size = " << listSize(head) << endl;
    insertAfter(head, 10, 299);
    F_traverse(head);
    R_traverse(tail);
}