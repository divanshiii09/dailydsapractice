#include<iostream>
#include<stack>
using namespace std;
// this code is to print the last element of the stack using recursion
//tc and sc is O(n)
void printtail(stack <int> &s, int n){
if(s.size()==1){
    cout<<s.top();
    return;
}
int digit= s.top();
s.pop();
printtail(s,n);
s.push(digit);
}

int main(){
    stack <int> s;
    for(int i=1;i<=5;i++){
        s.push(i*20);
    }
int n= s.size();
    printtail(s,n);
}