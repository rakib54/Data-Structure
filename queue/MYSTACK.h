#include <bits/stdc++.h>
using namespace std;

template <typename N> class Node{
public:
    N value;
    Node *next;
    Node *prev;

    Node(N val){
        value = val;
        next = NULL;
        prev = NULL;
    }
};

template<typename S> class Stack{
    Node <S> *head;
    Node <S> *top;
    int count = 0;

public:
    Stack(){
        head = NULL;
        top = NULL;
    }
    // push
    void push(S val){
        Node<S> *newNode = new Node<S>(val);
        if(head == NULL){
            head = top = newNode;
            count++;
            return;
        }
        top->next = newNode;
        newNode->prev = top;
        top = newNode;
        count++;
    }

    // pop
    S pop(){
        Node <S> *delNode;
        delNode = top;
        S chk;
        if(head == NULL){ // if there is no element
            cout<<"Stack underflow"<<endl;
            return chk;
        }

        if(top == head){  // if there is 1 element
            head = top = NULL;
        }
        else {            // if there is multiple element
            top = delNode->prev;
            top->next = NULL;
        }
        count--;
        chk = delNode->value;
        delete delNode;
        return chk;
    }

    // size
    int Size() {
        return count;
    }

    // check stack is empty or not
    bool Empty(){
        if(head == NULL) return true;
        else return false;
    }

    // top value
    S Top(){
        if(top == NULL){
            cout<<"Stack Underflow! There is no element in the stack"<<endl;
        }
        else return top->value;
    }

};