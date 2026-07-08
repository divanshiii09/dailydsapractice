#include <iostream>
#include <stack>
using namespace std;

// Function to insert an element at the bottom of the stack
// tc and sc is O(n)
void insertAtBottom(stack<int> &s, int x) {
    // Base Case
    if (s.empty()) {
        s.push(x);
        return;
    }

    int temp = s.top();
    s.pop();

    insertAtBottom(s, x);

    s.push(temp);
}

// Function to reverse the stack
void reverse(stack<int> &s) {
    // Base Case
    if (s.empty()) {
        return;
    }

    int temp = s.top();
    s.pop();

    reverse(s);

    insertAtBottom(s, temp);
}
// Driver code
int main() {
    stack<int> s;

    for (int i = 1; i <= 5; i++) {
        s.push(i * 10);
    }

    reverse(s);

    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}