#include<iostream>
using namespace std;

class Queue{
private:
int *arr;
int size;
int front;
int rear;
int count;
public:

Queue(int capacity){
    this->size=capacity;
    arr=new int[capacity];
    front=-1;
    rear=-1;
    count=0;
}

void enqueue(int value){
if(rear==size-1){
    cout<<"Queue Overflow"<<endl;
    return;
}
else if(front==-1){
    front=0;
    rear=0;
    arr[rear]=value;
}
else{
    rear++;
    arr[rear]=value;
}
count++;
}

void dequeue(){
if(front==-1){
    cout<<"Queue Underflow"<<endl;
    return;
}
else if(front==rear){
    front=-1;
    rear=-1;
}
else{
    front++;
}
count--;
}
int getfront(){
    if(front == -1){
        cout<<"Queue is empty"<<endl;
        return 0;
    }
    return arr[front];
}
int getrear(){
    if(rear == -1){
        cout<<"Queue is empty"<<endl;
        return 0;
    }
    return arr[rear];
}
int getsize(){
    return count;
    // return rear-front+1;
}
bool isempty(){
    return front == -1;
}
};


int main(){
Queue q(5);
q.enqueue(10);
q.enqueue(20);
q.enqueue(30);
cout<<"Front element is: "<<q.getfront()<<endl;
cout<<"Rear element is: "<<q.getrear()<<endl;
cout<<"Size of queue is: "<<q.getsize()<<endl;
cout<<"Is queue empty? "<<q.isempty()<<endl;
}