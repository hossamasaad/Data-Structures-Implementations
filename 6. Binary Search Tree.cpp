/*
 * Author : Hossam Asaad
 * Not Finish Yet
 */
 
#include <bits/stdc++.h>

using namespace std;


/*
 *  Create the structure
 */

struct Node{
    int value ;
    Node *left;
    Node *right;
    Node *parent;
};

/*
 *  pointer point to the root
 */

Node *root = NULL;

/*
 *  Functions prototype
 */

Node* LeftDescendant(Node *ptr);
Node* RightAncestor(Node *ptr);
Node* Find(int v,Node *ptr);
Node* Next(Node *ptr);
void Insert(int v,Node *ptr);
vector<int> RangeSearch(int x, int y, Node *root);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}


/*
 *  create a function to find element
 */

Node* Find(int v,Node *ptr){

    if(ptr->value == v)
        return ptr;

    else if(ptr->value > v){

        if(ptr->right != NULL)
            return Find(v,ptr->right);

        return ptr;
    }
    else if(ptr->value < v){
        if(ptr->left != NULL)
            return Find(v,ptr->left);

        return ptr;
    }
}

/*
 *  Create a function to find element can replace another element
 */

Node* Next(Node *ptr){
    if(ptr->right!=NULL)
        return LeftDescendant(ptr->right);
    else
        return RightAncestor(ptr);
}

Node* LeftDescendant(Node *ptr){
    if(ptr->left == NULL)
        return ptr;

    else
        return LeftDescendant(ptr->left);
}

Node* RightAncestor(Node *ptr){
    if(ptr->value < ptr->parent->value)
        return ptr->parent;

    else
        return RightAncestor(ptr->parent);
}

/*
 *  Create a function to make a range search
 */

vector<int> RangeSearch(int x, int y, Node *root){
    vector<int> range;
    Node *minPtr = Find(x,root);

    while(minPtr->value <= y){
        if(minPtr->value >= x){
            range.push_back(minPtr->value);
        }
        minPtr = Next(minPtr);
    }

    return range;
}

/*
 *  Create a function tom insert Node as a Leaf
 */

void Insert(int v,Node *ptr){
    Node *tmp = Find(v,ptr);
    Node *now;

    now->left   = NULL;
    now->right  = NULL;
    now->parent = tmp ;
    now->value  = v   ;

    if(tmp->value > v){
        tmp->left = now;
    }else{
        tmp->right = now;
    }
}
