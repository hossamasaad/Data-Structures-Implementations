/*
 * Author : Hossam Asaad
 * Queue Implementation with Linked List
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

void enqueue(int v){
    Node *node  = (struct Node*) malloc(sizeof(struct Node));
    node->value = v;
    node->next  = head;
    head = node;
    if(tail == NULL) tail = node;
}

int dequeue(){
	Node *tmp;
	tmp = head;
    if(head==NULL) return NULL;
    head = head->next;
    if(head==NULL) tail = NULL ;
    return tmp->value;
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
    enqueue(5); // 5
    cout << "is Empty ? : " << isEmpty() << endl;  // 0
    cout << "Size is: " << getSize() << endl; // 1
    enqueue(4); // 5 4
    enqueue(3); // 5 4 3
    cout << "Size is: " << getSize() << endl; // 3
    cout << dequeue() << " " << dequeue() << " " << dequeue() << endl; // 5 4 3
    cout << "Size is: " << getSize() << endl; // 0
    cout << "is Empty ? : " << isEmpty() << endl;  // 1
    return 0;
}
