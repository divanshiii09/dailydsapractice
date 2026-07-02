#include<iostream>
using namespace std;

class node{
public:
int data;
node*next;

node(int value){
    this->data= value;
    this->next=NULL;
}
};

void insertattail(int value, node*& head, node*&tail){
    //empty list
    if(head==NULL){
    node* newnode=new node(value);
    head=newnode;
    tail=newnode;
    tail->next=head;
    }else{
            node* newnode=new node(value);
            tail->next=newnode;
            tail=newnode;
            tail->next=head;
    }
}

void print(node*head){
     if (head == NULL)
    {
        cout << "List is Empty" << endl;
        return;
    }
    node *temp= head;
    do{
        cout<<temp->data<<"->";
temp=temp->next;
    }while(temp!=head);

}

int length(node*head){
if (head==NULL){
    return 0;
}
int count=0;
node*temp= head;
do{
count++;
temp=temp->next;
}while(temp!=head);
return count;

}
int main(){
node *head = NULL;
    node *tail = NULL;

    insertattail(10,head, tail);
    insertattail(20,head, tail);
    insertattail(30,head, tail);
    insertattail(40,head, tail);
    insertattail(50,head, tail);

    cout << "Circular Linked List: ";
    print(head);

    cout << "Length = " << length(head) << endl;

    return 0;
}