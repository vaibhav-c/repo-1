#include <iostream>
//#include <bits/stdc++.h>
using namespace std;

// Create A class node

class node
{
public:
    int data;
    node *next;

    // Node Class Constructor
    node(int val)
    {
        data = val;
        next = NULL;
    }
};

// Insert Element At Tail

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

//Insert at middle
void insertAtMid(node *&head, int val)
{
    node *n = new node(val);
    if (head == NULL)
    {
        head = n;
        return;
    }
    int len=0;
    node *temp = head;
    while (temp != NULL)
    {
        len++;
        
        temp = temp->next;
    }
    cout<<"length of list:"<<len<<endl;
    int pos= (len%2==0)? len/2: (len+1)/2;
    cout<<"position:"<<pos<<endl;

    node*curr= head;
    for (int i=1; i<pos; i++)
    {
        curr= curr->next;
    }
    n->next= curr->next;
    curr->next=n;

}


// Display All Element

void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Insert At Head

void insertAtHead(node *&head, int val)
{
    node *n = new node(val);
    n->next = head;
    head = n;
}

// Deleting in LL
void deletehead(node* &head)
{
    node* todelete= head;
    head= head->next;
    delete todelete;
}

void deletion(node* &head, int val)
{
    if (head== NULL)
    {
        return;
    }
    if (head->next== NULL)
    {
        deletehead(head);
        return;
    }
    node*temp=head;
    while(temp->next->data!=val)
    {
        temp= temp->next;
    }
    node* todelete= temp->next;
    temp->next= temp->next->next;
    delete todelete;
}

// Seraching  At Linked List

bool Search(node *head, int key)
{
    node *temp = head;
    while (temp->next != NULL)
    {
        if (temp->data == key)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

//REVERSING A LL
node* reverse(node* &head)
{
    node* prev= NULL;
    node* curr= head;
    node* nxt;
    while(curr!= NULL)
    {
        nxt= curr->next;
        curr->next= prev;
        prev= curr;
        curr= nxt;
    }
    return prev;
}

node* reccur(node* &head)
{
    if (head== NULL || head->next== NULL)
    {
        return head;
    }
    node* hnew= reccur(head->next);
    head->next->next= head;
    head->next= NULL;
    return hnew;
}

int main()
{

    node *head = NULL;
    insertAtTail(head, 10);
    insertAtTail(head, 20);
    insertAtTail(head, 30);
    insertAtTail(head, 40);
    insertAtTail(head, 50);
    //insertAtTail(head, 788);
    display(head);

    insertAtMid(head, 35);
    display(head);
    
    insertAtHead(head, 345);
    display(head);

    deletehead(head);
    display(head);

    deletion(head, 788);
    display(head);
    //cout << Search(head, 178);
    cout<<endl;

    cout<< "AFTER REVERSING: "<<endl;
    node* newhead= reverse(head);
    display(newhead);
    cout<<endl;
    
    cout<< "AFTER RECCURSIVE REVERSING: "<<endl;
    node* headnew= reccur(head);
    display(newhead);
    
    return 0;
}