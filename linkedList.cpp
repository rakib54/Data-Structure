#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};
void printList(Node* head){
    Node *tmp = head;
    while(tmp != NULL){
        cout<<tmp->data<<" ";
        tmp = tmp->next;
    }
}

void ListInsert(Node* &head,int pos,int val){
    if(pos == 0){
        Node *newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        return;
    }

    pos--;
    Node *tmp = head;
    for(int i=0;i<pos;i++){
        tmp = tmp->next;
    }
    Node *newNode = new Node(val);
    Node *save_next = tmp->next;
    tmp->next = newNode;
    newNode->next = save_next;
}

void deleteList(Node* &head, int pos){
    if(pos == 0){
        head = head->next;
        return;
    }
    pos--;
    Node *tmp = head;
    for(int i=0;i<pos;i++){
        tmp = tmp->next;
    }
    Node *save = tmp->next->next;   // go forward 2 steps to find delete element's next Node
    delete(tmp->next);    // delete elements
    tmp->next = save;

}

int main () {
    Node *head  = new Node(5);
    Node * first = new Node(10);
    Node * second = new Node(20);
    head->next = first;
    first->next = second;

    ListInsert(head,0,100);
    deleteList(head,1);
    printList(head);

    return 0;
}
