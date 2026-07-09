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

void preorder(Node* root){
    if(root==NULL){
        return;
    }
    // NLR
    cout<< root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root){
    if(root==NULL){
        return;}
    // LNR
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
    }

void postorder(Node* root){
    if(root==NULL){
        return;}
    // LRN
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
    }

int main(){
    Node* root= createtree();
    cout<<"Root node is "<<root->data<<endl;
    cout<<"Preorder traversal: ";
    preorder(root);
    cout<<endl;
    cout<<"Inorder traversal: ";
    inorder(root);  
    cout<<endl;
    cout<<"Postorder traversal: ";
    postorder(root);
}