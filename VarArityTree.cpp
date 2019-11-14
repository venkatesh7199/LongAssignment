/* every node has 4 components:
1. its key
2. its right sibling(if any)
3. its leftmost child (if any)
4. its parent(if it is the leftmost child) or its left sibling(if it is not leftmost child)

this structure supports 4 operations
1. swap nodes
	given the addresses of two nodes, its swaps them without changing the 		addresses of the given nodes.
2. insertnode
	given the address of the parent node (or left sibling if it is not the 		leftmost child),the key of the node to be inserted, and whether it is to be 		inserted as the leftmost child or as the right sibling, it creates a node 	  and inserts it as desired.
3. deletenode
	given the address of any node, it deletes that node and returns the address 		of the node that replaces it. This returned address is needed to be set as 		the new root in case we are deleting the root.  
4. traversal
	this function prints the key of the children of a node and then prints the 		key of the node, followed by the key of its right sibling(if it doesnt have 		children otherwise its children's keys are printed first).
*/

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
    Node* leftMChild;
    Node* rightSibling;
    Node* Parent;

};

struct Node* CreateNode (){

    struct Node * newNode =(struct Node*)malloc(sizeof(struct Node));
    return newNode;
}

void SwapNodes (struct Node* root, struct Node* temp){

    struct Node* temp2;

    temp2 = temp->rightSibling;
    temp->rightSibling = root->rightSibling;
    if(temp->rightSibling != NULL ) temp->rightSibling->Parent = temp;
    root->rightSibling = temp2; 
    if(temp2 != NULL ) temp2->Parent = root;


    temp2 = temp->leftMChild;
    temp->leftMChild = root->leftMChild;
    if(temp->leftMChild != NULL )temp->leftMChild->Parent = temp;
    root->leftMChild = temp2;
    if(temp2 != NULL )temp2->Parent = root;


    temp2 = temp->Parent;
    temp->Parent = root->Parent;
    
    if(temp->Parent != NULL ){

        if(temp->Parent->rightSibling == root){
            temp->Parent->rightSibling = temp;
        }
        else {
            temp->Parent->leftMChild = temp;
        }

    }
        
    root->Parent = temp2;

    if(temp2 != NULL ){ 

        if(temp2->rightSibling == temp){
            temp2->rightSibling = root;
        }
        else {
            temp2->leftMChild = root;
        }

    }

    return;

}


struct Node* InsertNode (struct Node* root, ll x, bool PSFlag){

    struct Node* temp = CreateNode();

    temp->keys=x;
    if(PSFlag){

        if(root != NULL )temp->rightSibling = root->rightSibling;
        temp->Parent = root;
        
        if(root != NULL && root->rightSibling !=NULL )root->rightSibling->Parent = temp;
        if(root != NULL )root->rightSibling = temp;

        temp->leftMChild = NULL;
        if(root == NULL ) temp->rightSibling = NULL;

    }

    else {

        if(root != NULL )temp->leftMChild = root->leftMChild;
        temp->Parent = root;

        if(root != NULL && root->leftMChild !=NULL )root->leftMChild->Parent = temp;
        if(root != NULL )root->leftMChild = temp;

        temp->rightSibling = NULL;
        if(root == NULL ) temp->leftMChild = NULL;
    }

    return temp;

}


struct Node* DeleteNode (struct Node* root ){

    


    if (root->rightSibling == NULL){

        if(root->leftMChild != NULL )root->leftMChild->Parent = root->Parent;
        
        if(root->Parent != NULL ){
            if (root->Parent->rightSibling == root){
                root->Parent->rightSibling = root->leftMChild;
            }
            else{
                root->Parent->leftMChild = root->leftMChild;
            }
        }
        free(root);
        return root->leftMChild;
    }

    else if (root-> leftMChild == NULL){

        if(root->rightSibling != NULL )root->rightSibling->Parent = root->Parent;
        
        if(root->Parent != NULL ){
            if (root->Parent->rightSibling == root){
                root->Parent->rightSibling = root->rightSibling;
            }
            else{
                root->Parent->leftMChild = root->rightSibling;
            }
        }

        free(root);
        return root->rightSibling;

    }

    else {

        struct Node* temp = root->rightSibling;

        struct Node* temp2;

        while (temp->leftMChild!=NULL){

            temp=temp->leftMChild;

        } 

        SwapNodes(root,temp);

        DeleteNode (root);

        return temp;

    }


}

void Traversal (struct Node* root){

    if(root == NULL)return;

    if( root->leftMChild != NULL ) Traversal (root->leftMChild);

    cout<< (root->keys) <<endl;

    if( root->rightSibling != NULL ) Traversal (root->rightSibling);

    return;

}

int main(){

     ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    struct Node* root = NULL;

    root= InsertNode(root,15,true);
    InsertNode(root,2235,false);
    InsertNode(root,23435,true);
    InsertNode(root,42345,true);

    Traversal(root);

    return 0;

}
