#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int value;
    Node *next;
    Node *prev;

    Node(int val){
        value = val;
        next = NULL;
        prev = NULL;
    }
};

class Stack{
    Node *head;
    Node *top;
    int count = 0;


public:
    Stack(){
        head = NULL;
        top = NULL;
    }
    // push
    void push(int val){
        Node *newNode = new Node(val);
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
    int pop(){
        Node *delNode;
        delNode = top;
        int chk = -1;
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
    int Top(){
        if(top == NULL){
            cout<<"Stack Underflow! There is no element in the stack"<<endl;
            return -1;
        }
        else return top->value;
    }

};
