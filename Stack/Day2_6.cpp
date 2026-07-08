#include<iostream>
#include<stack>
using namespace std;
// with using another stack and not using recursion
//tc and sc is O(n)
void reverse(stack<int> &s){
  stack<int> temp;
  while(!s.empty()){
    temp.push(s.top());
    s.pop();
  }
  s=temp;
}
int main(){
    stack <int> s;
    for(int i=1;i<=5;i++){
        s.push(i*20);
    }
    reverse(s);
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}