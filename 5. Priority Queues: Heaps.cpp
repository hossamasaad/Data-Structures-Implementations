/*
 * Author : Hossam Asaad
 */
 
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int  parent    (int i);
int  leftChild (int i);
int  rightChild(int i);
void siftUp    (int i);
void siftDown  (int i);
void Insert    (int p);
int extractMax();
void Remove(int i);
void changePriority(int i,int p);

int size = 0;
const int maxSize = 13;
int H[maxSize];

int main() {
    H[0] = 10000 ; // not in heap
                            H[1] = 45;
                H[2] = 35;              H[3] = 20;
         H[4] = 25;    H[5] = 15;     H[6]=12;   H[7] = 15;

    size = 7;
    cout << H[parent(5)] << endl;
    cout << H[leftChild(2)] << endl;
    cout << H[rightChild(2)] << endl;
    Insert(50);
    cout << H[1] << endl ;
    changePriority(1,80);
    cout << H[1] << endl ;
    cout << extractMax() << endl;
    cout << H[1] << endl;
}

int parent    (int i){
    return i/2 ;
}

int leftChild (int i){
    return 2*i;
}

int rightChild(int i){
    return 2*i+1;
}

void siftUp   (int i){
    while(i>0 && H[parent(i)]<H[i]){
        swap(H[i],H[parent(i)]);
        i = parent(i);
    }
}

void siftDown (int i){
    int maxIdx = i;

    int l = leftChild(i);
    if(l<=size && H[l]>H[maxIdx]){
        maxIdx = l;
    }

    int r = rightChild(i);
    if(r<=size && H[r]>H[maxIdx]){
        maxIdx = r;
    }

    if(i!=maxIdx){
        swap(H[i] , H[maxIdx]);
        siftDown(maxIdx);
    }
}

void Insert   (int p){
    if(size == maxSize) return;
    size++;
    H[size] = p;
    siftUp(size);
}

int extractMax(){
    int result = H[1];
    H[1] = H[size];
    size--;
    siftDown(1);
    return result;
}

void Remove(int i){
    H[i] = 9999999;
    siftUp(i);
    extractMax();
}

void changePriority(int i,int p){
    int oldP = H[i];
    H[i] = p;
    if(p>oldP) siftUp(i);
    else siftDown(i);
}
