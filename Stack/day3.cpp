#include <iostream>
#include <stack>
using namespace std;
// this code is to insert an element in a sorted stack using recursion
void insertSorted(stack<int> &s, int x) {

    // Insert if stack is empty or x belongs on top
    if (s.empty() || x > s.top()) {
        s.push(x);
        return;
    }

    int temp = s.top();
    s.pop();

    insertSorted(s, x);

    s.push(temp);
}

int main() {

    stack<int> s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    int x = 23;

    insertSorted(s, x);

    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
}