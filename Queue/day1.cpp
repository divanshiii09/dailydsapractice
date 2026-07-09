#include<iostream>
#include<queue>
using namespace std;

int main(){
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    // cout << q.front() << " " << q.back() << endl;
    // while(!q.empty()){
    //     cout<< q.front()<<" ";
    //     q.pop();
    // }


    deque <int> dq;
    dq.push_front(10);
    dq.push_front(20);
    dq.push_back(30);
    dq.push_back(40);
    dq.push_front(50);
    cout << dq.front() << " " << dq.back() << endl;
    dq.pop_back();
    dq.pop_front();
    while(!dq.empty()){
        cout<< dq.front()<<" ";
        dq.pop_front();
    }

  
}