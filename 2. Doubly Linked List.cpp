/*
 * Author : Hossam Asaad
 * Doubly Linked List
 */

#include <iostream>
#include <stdlib.h>

using namespace std;

struct Node{
    int value;
    Node *next;
    Node *last;
};

Node *head = NULL;
Node *tail = NULL;

void pushBack(int v){
    Node *node  = (struct Node*) malloc(sizeof(struct Node));
    node->value = v;
    node->next  = NULL;
    if(tail == NULL){
        tail = node;
        head = node;
        node->last=NULL;
    }else{
        tail->next = node;
        node->last = tail;
        tail = node;
    }
}

void popBack(){
    if(head == NULL){
        return;
    }
    if(head == tail){
        head = NULL;
        tail = NULL;
    }
    else{
        tail = tail->last;
        tail->next = NULL;
    }
}

void pushFront(int v){
    Node *node  = (struct Node*) malloc(sizeof(struct Node));
    node->value = v;
    node->next  = head;
    node->last  = NULL;
    head = node;
    if(tail == NULL){
        tail = node;
    }
}

void popFront(){
    if(head==NULL) return;
    head = head->next;
    head->last = NULL;
    if(head==NULL) tail = NULL ;
}

void addAfter(Node *node,int v){
    Node *node2  = (struct Node*) malloc(sizeof(struct Node));
    node2->value = v ;
    node2->next = node->next;
    node2->last = node;
    node->next = node2;
    if(node2->next!=NULL){
        node2->next->last=node2;
    }
    if(tail==node){
        tail = node2;
    }
}

void disply(){
    Node *tmp ;
    tmp = head;
    while( tmp != NULL){
        cout << tmp->value << " " ;
        tmp = tmp->next ;
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

    cout  << isEmpty() << endl;
    pushBack(5);            // 5
    pushBack(3);            // 5 3
    pushFront(6);           // 6 5 3
    addAfter(head->next,4); // 6 5 4 3
    popBack();              // 6 5 4
    popFront();             // 5 4
    cout << isEmpty() << endl;
    cout << "Size is: " << getSize() << endl;
    disply();
    return 0;
}
