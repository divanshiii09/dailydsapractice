#include <iostream>
using namespace std;
// this code is to implement doubly linked list
class node
{

public:
    node *prev;
    int data;
    node *next;

    node(int value)
    {
        this->data = value;
        this->prev = NULL;
        this->next = NULL;
    }
};
int length(node *head)
{
    int count = 0;
    node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}
void insertathead(int value, node *&head, node *&tail)
{
    // list is emplty
    if (head == NULL)
    {
        node *newnode = new node(value);
        head = newnode;
        tail = newnode;
    }
    else
    {
        node *newnode = new node(value);
        head->prev = newnode;
        newnode->next = head;
        head = newnode;
    }
}

void insertattail(int value, node *&head, node *&tail)
{
    // list is empty
    if (head == NULL)
    {
        node *newnode = new node(value);
        head = newnode;
        tail = newnode;
    }

    else
    {

        node *newnode = new node(value);
        newnode->prev = tail;
        tail->next = newnode;
        tail = newnode;
    }
}

void insertatposition(int position, int value, node *&head, node *&tail)
{
    if (position == 1)
    {
        insertathead(value, head, tail);
    }
    else if (position == length(head) + 1)
    {
        insertattail(value, head, tail);
    }
    else
    {
        node *newnode = new node(value);
                node *temp = head;

        for (int i = 1; i < position - 1; i++)
        {
            temp = temp->next;
        }
        node *temp2 = temp->next;

        temp->next = newnode;
        newnode->prev = temp;
        newnode->next = temp2;
        temp2->prev = newnode;
    }
}

void print(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void reverseprint(node *tail)
{
    node *temp = tail;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->prev;
    }
    cout << "NULL" << endl;
}
int search(int target, node *head, node * tail){
    node*temp= head;
    int count=0;
    while(temp!=NULL){
        count++;
        if(temp->data == target){
            return count;
        }
        temp=temp->next;
    }
    return -1;
}
void deletenode(int position, node*&head, node*&tail){
// ll empty hai
if(head==NULL){
    cout<<"LL empty"<<endl;
    return;
}
if(head==tail){
    node*temp=head;
    head=NULL;
    tail=NULL;
    delete temp;
    return;
}
if(position==1){
    node*temp=head;
    node*temp2= temp->next;

    temp2->prev=NULL;
    temp->next=NULL;
    head=temp2;
    delete temp;
    return;
}

if(position== length(head)){
    node*temp=head;
for(int i=1; i<position-1;i++){
    temp=temp->next;
}
node*temp2=temp->next;

temp->next=NULL;
temp2->prev=NULL;
tail=temp;
delete temp2;
return;
}
node*temp=head;
for(int i=1; i<position-1;i++){
    temp=temp->next;
}
node*temp2=temp->next;
node*temp3=temp2->next;

temp->next=temp3;
temp2->next=NULL;
temp3->prev=temp;
temp2->prev=NULL;
delete temp2;
return;
}

int main()
{
    node *head = NULL;
    node *tail = NULL;

    insertathead(10, head, tail);
    insertathead(20, head, tail);
    insertattail(30, head, tail);
    insertatposition(4, 40, head, tail);
    insertatposition(1, 60, head, tail);
    //print(head);
    // reverseprint(tail);

    insertatposition(3, 70, head, tail);
    print(head);
    deletenode(1,head,tail);
    deletenode(3,head,tail);
    deletenode(4,head,tail);
    print(head);

    // cout<< search(90,head,tail);
}