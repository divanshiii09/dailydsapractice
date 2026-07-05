#include <iostream>
using namespace std;
// this code is to implement linked list
class node
{
public:
    int data;
    node *next;
    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
void insertathead(int value, node *&head, node *&tail)
{
    // jab first node insert kr rhe hai
    if (head == NULL && tail == NULL)
    {
        node *newnode = new node(value);
        head = newnode;
        tail = newnode;
    }
    // jab already node present ho
    else
    {
        // new node create kro
        node *newnode = new node(value);
        // pointer head pe lgao
        newnode->next = head;
        // head ko newnode pe lgao
        head = newnode;
    }
}

void insertattail(int value, node *&head, node *&tail)
{
    // abhi tak kuch nhi hai
    if (head == NULL && tail == NULL)
    {
        // create a node
        node *newnode = new node(value);
        head = newnode;
        tail = newnode;
    }
    else
    {
        node *newnode = new node(value);
        // tail ke next ko new code pr lgaye ge
        tail->next = newnode;
        // tail ko newnode pr lgaye ge
        tail = newnode;
    }
}
void print(node *&head)
{
    node *temp = head;
    while (temp != NULL)
    {
        // print the value
        cout << temp->data << "->";
        // update temp to next node
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int length(node *&head)
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

void insertatposition(int position, int value, node *&head, node *&tail)
{
    int len = length(head);
    if (position == 1)
    {
        insertathead(40, head, tail);
    }
    else if (position == len + 1)
    {
        insertattail(value, head, tail);
    }
    else
    {
        // create a newnode
        node *newnode = new node(value);
        node *temp = head;
        for (int i = 1; i < position - 1; i++)
        {
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
}

void search(int target, node *head)
{
    node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        if (temp->data == target)
        {
            cout << temp->data << " is present at " << count << endl;
        }
        temp = temp->next;
    }

    cout << temp->data << " is not present at " << endl;
}

void deletenode(int position, node *&head, node *&tail)
{
    // LL is empty---> no need to delete
    if (head == NULL && tail == NULL)
    {
        cout << "EMPTY LL" << endl;
        return;
    }
    int len = length(head);
    if (position < 1 || position > len)
    {
        cout << "Invalid Position" << endl;
        return;
    }
    if (head == tail)
    {
        node *temp = head;
        head = NULL;
        tail = NULL;
        delete temp;
        return;
    }
    if (position == 1)
    {
        node *temp = head;
        head = temp->next;
        temp->next = NULL;
        delete temp;
        return;
    }

      if (position == len) {
        node* temp = head;
        for (int i = 1; i < position - 1; i++) {
            temp = temp->next;
        }

        node* nodetodelete = temp->next;
        temp->next = NULL;
        tail = temp;
        delete nodetodelete;
    return;
    }
    else{
        node *temp = head;
        for (int i = 1; i < position - 1; i++)
        {
            temp = temp->next;
        }
        node *nodetodelete = temp->next;
        temp->next = nodetodelete->next;
        nodetodelete->next = NULL;
        delete nodetodelete;
        return;
        }
}

int main()
{
node*head=NULL;
node * tail=NULL;

insertathead(20,head,tail);
insertathead(10,head,tail);
insertattail(40,head,tail);
insertatposition(3,30,head,tail);

deletenode(4,head,tail);
deletenode(2,head,tail);
deletenode(1,head,tail);
deletenode(1,head,tail);
print(head);
}