#include<iostream>
#include<stack>
using namespace std;
// this code is to check if the stack is sorted or not using recursion
// tc and sc is O(n)
bool issorted(stack<int>&s, int n){
    if(s.size()==1){
        return true;
    }
    int digit= s.top();
    s.pop();
    bool isSorted = issorted(s,n);
    if(digit<s.top()){
        s.push(digit);
        return false;
    }
    s.push(digit);
    return isSorted;
}
int main(){
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    int n= s.size();

    bool result = issorted(s,n);
    if(result){
        cout<<"Stack is sorted";
    }
    else{
        cout<<"Stack is not sorted";
    }
}