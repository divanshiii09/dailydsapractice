#include <iostream>
using namespace std;

class Deque {
private:
    int *arr;
    int size;
    int front;
    int rear;

public:
    Deque(int capacity) {
        size = capacity;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    ~Deque() {
        delete[] arr;
    }

    void push_front(int value) {
        if (front == 0) {
            cout << "Deque Overflow" << endl;
            return;
        }

        if (front == -1) {
            front = rear = 0;
        }
        else {
            front--;
        }

        arr[front] = value;
    }

    void push_back(int value) {
        if (rear == size - 1) {
            cout << "Deque Overflow" << endl;
            return;
        }

        if (front == -1) {
            front = rear = 0;
        }
        else {
            rear++;
        }

        arr[rear] = value;
    }

    void pop_front() {
        if (front == -1) {
            cout << "Deque Underflow" << endl;
            return;
        }

        if (front == rear) {
            front = rear = -1;
        }
        else {
            front++;
        }
    }

    void pop_back() {
        if (front == -1) {
            cout << "Deque Underflow" << endl;
            return;
        }

        if (front == rear) {
            front = rear = -1;
        }
        else {
            rear--;
        }
    }

    int getfront() {
        if (front == -1) {
            cout << "Deque is empty" << endl;
            return -1;
        }
        return arr[front];
    }

    int getrear() {
        if (rear == -1) {
            cout << "Deque is empty" << endl;
            return -1;
        }
        return arr[rear];
    }

    int getsize() {
        if (front == -1)
            return 0;

        return rear - front + 1;
    }

    bool isempty() {
        return front == -1;
    }
};

int main() {
    Deque dq(5);

    dq.push_back(10);
    dq.push_back(20);
    dq.push_front(5);

    cout << "Front: " << dq.getfront() << endl;
    cout << "Rear: " << dq.getrear() << endl;
    cout << "Size: " << dq.getsize() << endl;

    dq.pop_front();
    dq.pop_back();

    cout << "\nAfter deletion:\n";
    cout << "Front: " << dq.getfront() << endl;
    cout << "Rear: " << dq.getrear() << endl;
    cout << "Size: " << dq.getsize() << endl;

    return 0;
}