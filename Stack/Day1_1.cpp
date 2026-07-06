#include<iostream>
using namespace std;
// this code is to implement stack using array
class Stack{
public:
    int *arr;
    int size;
    int top;
     
    Stack(int capacity){
        this->size=capacity;
        arr=new int[capacity];
        top=-1;
    }

    void push(int val){
        if(top==size-1){
            cout<<"Stack Overflow"<<endl;
            return;
        }
        top++;
        arr[top]=val;
    }

    void pop(){
        if(top==-1){
            cout<<"Stack Underflow"<<endl;
            return;
        }
        top--;
    }

    int getsize(){
        return top+1;
    }

    bool isempty(){
    if(top==-1){
        return true;
    }
    return false;
}
    int gettop(){
        if(top==-1){
            cout<<"Stack is empty"<<endl;
            return 0;
        }
        return arr[top];
    }
};
int main(){
    // initially top=-1
    // to push top++ and arr[top]=value
    // to pop top-- and return arr[top]
    Stack s(5);
        cout<<"Top element is: "<<s.gettop()<<endl;

    s.push(10);
    s.push(20);
    s.push(30);
    cout<<"Top element is: "<<s.gettop()<<endl;
    s.pop();
    cout<<"Top element is: "<<s.gettop()<<endl;
     s.push(10);
    s.push(20);
    s.push(30);
      s.push(30);
    return 0;
}