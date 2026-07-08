#include<iostream>
using namespace std;
// this code is to implement two stacks using array
// tc and sc is O(1)›
class Stack{
public:
int *arr;
int size;
int top1;
int top2;

Stack(int capacity){
    this->size=capacity;
    arr= new int[capacity];
    top1=-1;
    top2=size;
}

void push1(int value){
    if(top1+1==top2){
        cout<<"Stack Overflow"<<endl;
        return;
    }
top1++;
arr[top1]=value;
}

void push2(int value){
    if(top2-1==top1){
        cout<<"Stack Overflow"<<endl;
        return;
    }
    top2--;
    arr[top2]=value;
}

void pop1(){
    if(top1==-1){
        cout<<"Stack Underflow"<<endl;
        return;
    }
    arr[top1]=0;
    top1--;
}

void pop2(){
    if(top2==size){
        cout<<"Stack Underflow"<<endl;
        return;
    }
    arr[top2]=0;
    top2++;
}

void print(){
    cout<<"Stack 1: ";
    for(int i=0;i<=top1;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<"Stack 2: ";
    for(int i=top2;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}};
int main(){
    Stack s(5);
    s.push1(1);
    s.push1(2);
    s.push2(5);
    s.push2(4);
    s.push2(3);
    s.print();
    s.push1(6);
    // s.push2(8);

}