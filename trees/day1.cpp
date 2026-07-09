#include<iostream>
using namespace std;

class Node{
public:
int data;
Node* left;
Node* right;
Node(int value){
    this->data=value;
    this->left=NULL;
    this->right=NULL;
}
};
Node * createtree(){
    int value;
    cout<<"Enter value for the node ";
    cin>>value;
    if(value==-1){return NULL;}
    else{
        Node* root= new Node(value);
        cout<<"Enter left child of "<<value<<endl;
        root->left= createtree();
        cout<<"Enter right child of "<<value<<endl;
        root->right=createtree();
        return root;
    }
}
int main(){
    Node* root= createtree();
    cout<<"Root node is "<<root->data<<endl;
}