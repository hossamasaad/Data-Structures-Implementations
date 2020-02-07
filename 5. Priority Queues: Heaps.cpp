#include <bits/stdc++.h>

using namespace std;

const int max_size = 10;                             // maximum size of the heap
int H[max_size];                                     // The Heap
int N = 5;                                           // current size of heap

int parent(int i)                                    // return the parent of node i
{
    return i/2;
}

int left_child(int i)                                // return left child of node i
{
    return 2*i;
}

int right_child(int i)                               // return right child of node i
{
    return 2 * i + 1;
}

void sift_up(int i)                                  // sift up node i to the right place
{
    while( i>0 && H[ parent(i) ] < H[i] ){
        swap(H[ parent(i) ], H[i]);
        i = parent(i);
    }
}

void sift_down(int i,int N)                          // sift down node i to the right place
{
    int l = left_child(i);
    int r = right_child(i);

    int largest = i;

    if( l <= N && H[l] > H[i])
        largest = l;

    if( r <= N && H[r] > H[largest])
        largest = r;

    if(i!=largest){
        swap(H[i],H[largest]);
        sift_down(i,N);
    }
}

void build_heap()                                    // build heap after inserting data
{
    for(int i=N/2;i>=1;i--)
    {
        sift_down(i,N);
    }
}

void Insert(int p)                                   // To insert point  tot the heap
{
    if(N == max_size) return;
    N++;
    H[N] = p;
    sift_down(N,N);
}

int extract_max()                                    // extract max element (root) in the heap
{
    int result = H[1];
    H[1] = H[N];
    N--;
    sift_down(1,N);
    return result;
}

void Remove(int i)                                   // Remove an element and index i
{
    H[i] = 9999999;
    sift_up(i);
    extract_max();
}

void change_priority(int i, int p)
{
    int old_p = H[i];
    H[i] = p;

    if(old_p > p) sift_down(i,N);
    else sift_up(i);
}

void heap_sort()
{
    build_heap();
    int heap_size = N;
    for(int i = N; i>=2 ; i-- )
    {
        swap(H[ 1 ], H[ i ]);
        heap_size--;
        sift_down(1,heap_size);
    }
}

int main() {
    H[0] = 99999;
    H[1] = 5;
    H[2] = 4;
    H[3] = 10;
    H[4] = 12;
    H[5] = 1;

    heap_sort();
    for(int i=1;i<=N;i++)
        cout << H[i] << endl;
    return 0;
}
