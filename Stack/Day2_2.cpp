#include<iostream>
#include<stack>
using namespace std;
// this is code for printing the middle element of stack using recursion
// tc and sc is O(n)
void printmid(stack<int> &s,int n){
    if(s.size()==n/2+1){
        cout<<s.top();
        return;
    }
    int digit =s.top();
    s.pop();
    printmid(s,n);
    s.push(digit);
}

int main(){
    stack<int> s;
    for (int i=1;i<=11;i++){
        s.push(i*10);
    }

int n= s.size();
    printmid(s,n);
}