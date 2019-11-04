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


struct Node* Search (struct Node* root, ll x){

    if(x == root->keys ) return root;
    if(x > root->keys ) {
        if(root->rightChild != NULL){    
            return Search(root->rightChild, x);
        }
        else return root;
    }
    
    if(root->leftChild != NULL){    
            return Search(root->leftChild, x);
        }
    else return root;

}


struct Node* Insert(struct Node* root, ll x){

    if(root != NULL ){
        struct Node* temp = Search(root, x);
        if(temp->keys == x)return root;
        if(temp->keys > x){
            InsertNode(temp, x, false);
        }
        else{
            InsertNode(temp, x, true);
        }
        return root;
    }

    root = InsertNode(root, x, true);
    return root;
}


struct Node* Delete(struct Node* root, ll x){

    struct Node* temp = Search(root, x);
    
    if(temp == root){
        if(temp->keys == x) {
            temp = DeleteNode(temp);
            return temp;
        }
        return temp;
    }
    
    if(temp->keys == x) DeleteNode(temp);
    
    return root;
    
}



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    struct Node* root = NULL;

    while(1){

        int com;
        ll x;
        cin>>com;
        
        if(com == 0 ) InorderTraversal(root);
        else if(com == 1) {
            cin>>x;
            root = Insert(root, x);
        }
        else if(com == 2){
            cin>>x;
            root = Delete(root, x);
        }
        else{
            break;
        }

    }

    return 0;
}
/*
	INPUT format
	first input is command type;
	
	0 - inorder traversal
	prints keyss, heights, and parents of nodes in order.
	
	1- insertion
	prompts another input and inserts it in the tree;
	does nothing if key already exists;
	
	2 - deletion
	prompts another input and inserts it in the tree;
	does nothing if key doesnt exist;
	
	
*/	
