#include <bits/stdc++.h>
using namespace std;

template <typename N> class QueueNode{
public:
    N value;
    QueueNode *next;

    QueueNode(N val){
        value = val;
        next = NULL;
    }
};

template <typename Q> class Queue {
    QueueNode<Q> *front;
    QueueNode<Q> *rear;
public:
    Queue() {
        front = NULL;
        rear = NULL;
    }

    // enqueue ->push
    void push(Q val) {
        QueueNode<Q> *newNode = new QueueNode<Q>(val);
        if(front == NULL) {
            front  = rear = newNode;
            return;
        }
        rear->next = newNode;
        rear = rear->next;
    }

    // dequeue ->pop
    Q pop(){
        Q chk;
        if(rear == NULL){
            cout<<"Queue Underflow!!"<<endl;
            return chk;
        }
        QueueNode<Q> *delNode;
        delNode = front;
        front = front->next;
        if(front == NULL) {
            rear = NULL;
        }
        chk = delNode->value;
        delete delNode;
        return chk;
    }

    // peek ->front() back()
    Q Front() {
        Q chk;
        chk = front->value;
        return chk;
    }

    Q Back() {
        Q chk;
        chk = rear->value;
        return chk;
    }

    // Empty
    bool Empty() {
        if(front == NULL && rear == NULL){
            return true;
        }
        else return false;
    }
};