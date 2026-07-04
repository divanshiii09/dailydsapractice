#include<iostream>
#include<stack>
using namespace std;
// this code is to reverse the stack using recursion with time complexity of O(n^2) and space complexity of O(n)
int main(){
    stack <char> s;
    string str= "string";
    for(int i=0; i<str.length();i++){
        s.push(str[i]);
    }

    while(!s.empty()){
        cout<<s.top();
        s.pop();
    }
}
