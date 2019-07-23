/*
 * Author : Hossam Asaad
 * Stack Implementation with Linked List
 */

#include <iostream>
#include <stdlib.h>

using namespace std;

struct Node{
    int value;
    Node *next;
};

Node *head = NULL;
Node *tail = NULL;

void push(int v){
    Node *node  = (struct Node*) malloc(sizeof(struct Node));
    node->value = v;
    node->next  = head;
    head = node;
    if(tail == NULL) tail = node;
}

int pop(){
	Node *p;
    if(head == NULL){
        return NULL;
    }
    if(head == tail){
    	p = head;
        head = NULL;
        tail = NULL;
        return p->value ;
    }
    else{
        Node *tmp ;
        tmp = head;
        while( tmp->next->next != NULL ){
            tmp = tmp->next;
        }
        p = tmp->next;
        tmp->next = NULL ;
        tail = tmp ;
        return p->value;
    }
}

bool isEmpty(){
    if(head==NULL) return true;
    return false;
}

int getSize(){
    int ctr=0;
    Node *tmp ;
    tmp = head;
    while( tmp != NULL){
        ctr++;
        tmp = tmp->next ;
    }
    return ctr;
}

int main() {

    cout << "is Empty ? : " <<  isEmpty() << endl;  // 1
    push(5); // 5
    cout << "is Empty ? : " << isEmpty() << endl;  // 0
    cout << "Size is: " << getSize() << endl; // 1
    push(4); // 5 4
    push(3); // 5 4 3
    cout << "Size is: " << getSize() << endl; // 3
    cout << pop() << " " << pop() << " " << pop () << endl; // 3 4 5
    cout << "Size is: " << getSize() << endl; // 0
    cout << "is Empty ? : " << isEmpty() << endl;  // 1
    return 0;
}
