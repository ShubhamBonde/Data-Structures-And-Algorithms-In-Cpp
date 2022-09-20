#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node* next;
};


void insertAtHead(struct Node* &head, struct Node* &tail, int data)
{
    struct Node* temp  = new Node();
    temp->data = data;
    temp->next = NULL;
    if (head == NULL) {
        head = temp;
        tail = temp;
    }
    else {
        
        temp->next = head;
        head = temp;
    }
    return;

}


void insertAtTail(struct Node* &h,struct Node* &t, int d)
{
    struct Node* temp = new Node();
    temp->data = d;
    temp->next = NULL;

    if (h == NULL) {
        h = temp;
        t = temp;
    }
    else {
        struct Node* tr = h;
        for (;tr->next != NULL; tr = tr->next );
        tr->next = temp;
        t = temp;
    }
    return;
}

void printList(struct Node* head)
{
    for(;head != NULL; head = head->next)
    {
        cout << head->data << "->";
    }
    cout << "NULL";
    return;
}

int main()
{
    struct Node* head = NULL;
    struct Node* tail = NULL;

    for (int i = 0; i <= 10; i++)
    {
        cout << "i = " << i << endl;
        // insertAtHead(head, tail, i);
        insertAtTail(head, tail, i);
    }
    printList(head);

}