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

    bool isempty() {
        return front == -1;
    }

    bool isfull() {
        return (front == (rear + 1) % size);
    }

    void push_front(int value) {

        if (isfull()) {
            cout << "Deque Overflow\n";
            return;
        }

        if (isempty()) {
            front = rear = 0;
        }
        else {
            front = (front - 1 + size) % size;
        }

        arr[front] = value;
    }

    void push_back(int value) {

        if (isfull()) {
            cout << "Deque Overflow\n";
            return;
        }

        if (isempty()) {
            front = rear = 0;
        }
        else {
            rear = (rear + 1) % size;
        }

        arr[rear] = value;
    }

    void pop_front() {

        if (isempty()) {
            cout << "Deque Underflow\n";
            return;
        }

        if (front == rear) {
            front = rear = -1;
        }
        else {
            front = (front + 1) % size;
        }
    }

    void pop_back() {

        if (isempty()) {
            cout << "Deque Underflow\n";
            return;
        }

        if (front == rear) {
            front = rear = -1;
        }
        else {
            rear = (rear - 1 + size) % size;
        }
    }

    int getfront() {

        if (isempty()) {
            cout << "Deque is empty\n";
            return -1;
        }

        return arr[front];
    }

    int getrear() {

        if (isempty()) {
            cout << "Deque is empty\n";
            return -1;
        }

        return arr[rear];
    }

    int getsize() {

        if (isempty())
            return 0;

        return (rear - front + size) % size + 1;
    }

    void display() {

        if (isempty()) {
            cout << "Deque is empty\n";
            return;
        }

        int i = front;

        while (true) {
            cout << arr[i] << " ";

            if (i == rear)
                break;

            i = (i + 1) % size;
        }

        cout << endl;
    }
};

int main() {

    Deque dq(5);

    dq.push_back(10);
    dq.push_back(20);
    dq.push_front(5);
    dq.push_back(30);
    dq.push_back(40);

    dq.display();

    cout << "Front = " << dq.getfront() << endl;
    cout << "Rear = " << dq.getrear() << endl;
    cout << "Size = " << dq.getsize() << endl;

    dq.pop_front();
    dq.pop_back();

    cout << "\nAfter deletion\n";

    dq.display();

    cout << "Front = " << dq.getfront() << endl;
    cout << "Rear = " << dq.getrear() << endl;
    cout << "Size = " << dq.getsize() << endl;

    return 0;
}