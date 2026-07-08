#include<iostream>
#include<stack>
using namespace std;

//this code is to reverse the stack using another stack with time complexity of O(n) and space complexity of O(n)
//tc and sc is O(n)
stack<int> reverse(stack<int> &s){
 stack<int> temp;
 while(s.empty()==false){
temp.push(s.top());
s.pop();
}
return temp;
}
int main(){

    stack<int> s;
    for (int i=1; i<=5;i++){
        s.push(i*10);
    }
    cout<<endl;
    s=reverse(s);

    while(s.empty()==false){
        cout<< s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}