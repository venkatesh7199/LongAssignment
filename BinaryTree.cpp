#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define MP make_pair
#define PB push_back
#define N 100001
#define HOLE 1000000007

ll power(ll x,ll y)
{
      ll res = 1; // Initialize result

    while (y > 0) {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res * x)%HOLE;

        // n must be even now
        y = y >> 1; // y = y/2
        x = (x * x)%HOLE; // Change x to x^2
    }
    return res;
}

struct Node {

    ll keys;
    Node* leftChild;
    Node* rightChild;
    Node* Parent;

};

struct Node* CreateNode (){

    struct Node * newNode =(struct Node*)malloc(sizeof(struct Node));
    return newNode;
}

void SwapNodes (struct Node* root, struct Node* temp){

    struct Node* temp2;

    temp2 = temp->rightChild;
    temp->rightChild = root->rightChild;
    if(temp->rightChild != NULL ) temp->rightChild->Parent = temp;
    root->rightChild = temp2; 
    if(temp2 != NULL ) temp2->Parent = root;


    temp2 = temp->leftChild;
    temp->leftChild = root->leftChild;
    if(temp->leftChild != NULL )temp->leftChild->Parent = temp;
    root->leftChild = temp2;
    if(temp2 != NULL )temp2->Parent = root;


    temp2 = temp->Parent;
    temp->Parent = root->Parent;
    
    if(temp->Parent != NULL ){

        if(temp->Parent->rightChild == root){
            temp->Parent->rightChild = temp;
        }
        else {
            temp->Parent->leftChild = temp;
        }

    }
        
    root->Parent = temp2;

    if(temp2 != NULL ){ 

        if(temp2->rightChild == temp){
            temp2->rightChild = root;
        }
        else {
            temp2->leftChild = root;
        }

    }

    return;

}


struct Node* InsertNode (struct Node* root, ll x, bool LRFlag){

    struct Node* temp = CreateNode();

    temp->keys=x;
    if(LRFlag){

        if(root != NULL )temp->rightChild = root->rightChild;
        temp->Parent = root;
        
        if(root != NULL && root->rightChild !=NULL )root->rightChild->Parent = temp;
        if(root != NULL )root->rightChild = temp;

        temp->leftChild = NULL;
        if(root == NULL ) temp->rightChild = NULL;

    }

    else {

        if(root != NULL )temp->leftChild = root->leftChild;
        temp->Parent = root;

        if(root != NULL && root->leftChild !=NULL )root->leftChild->Parent = temp;
        if(root != NULL )root->leftChild = temp;

        temp->rightChild = NULL;
        if(root == NULL ) temp->leftChild = NULL;
    }

    return temp;

}


struct Node* DeleteNode (struct Node* root ){

    


    if (root->rightChild == NULL){

        if(root->leftChild != NULL )root->leftChild->Parent = root->Parent;
        
        if(root->Parent != NULL ){
            if (root->Parent->rightChild == root){
                root->Parent->rightChild = root->leftChild;
            }
            else{
                root->Parent->leftChild = root->leftChild;
            }
        }
        free(root);
        return root->leftChild;
    }

    else if (root-> leftChild == NULL){

        if(root->rightChild != NULL )root->rightChild->Parent = root->Parent;
        
        if(root->Parent != NULL ){
            if (root->Parent->rightChild == root){
                root->Parent->rightChild = root->rightChild;
            }
            else{
                root->Parent->leftChild = root->rightChild;
            }
        }

        free(root);
        return root->rightChild;

    }

    else {

        struct Node* temp = root->rightChild;

        struct Node* temp2;

        while (temp->leftChild!=NULL){

            temp=temp->leftChild;

        } 

        SwapNodes(root,temp);

        DeleteNode (root);

        return temp;

    }


}

void InorderTraversal (struct Node* root){

    if(root == NULL)return;

    if( root->leftChild != NULL ) InorderTraversal (root->leftChild);

    cout<< (root->keys) <<endl;

    if( root->rightChild != NULL ) InorderTraversal (root->rightChild);

    return;

}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    struct Node* root = NULL;

    root= InsertNode(root,15,true);
    InsertNode(root,25,false);
    InsertNode(root,35,true);
    InsertNode(root,45,true);

    InorderTraversal(root);

    return 0;
    
}