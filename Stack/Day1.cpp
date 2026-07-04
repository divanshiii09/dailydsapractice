#include<iostream>
#include<stack>
using namespace std;
// this code is to demonstrate the basic operations of stack in C++ STL
int main(){
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);

    cout<< s.size()<<endl;
    cout<< s.empty()<<endl;
    cout<<"Top element: "<<s.top()<<endl;
    s.pop();
    cout<<"Top element after pop: "<<s.top()<<endl;

}