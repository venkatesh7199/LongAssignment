#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define MP make_pair
#define PB push_back
#define N 100001
#define HOLE 1000000007


struct cnode
{
    int value;
    int p;
    cnode* leftp;
    cnode* rightp;
};
cnode* leftprotate(cnode* y)
{
    cnode* x= y->rightp;
    cnode* t2= x->leftp;
    x->leftp= y;
    y->rightp= t2;
    return x;
}

cnode* rightprotate(cnode* x)
{
    cnode* y= x->leftp;
    cnode* t2= y->rightp;
    y->rightp= x;
    x->leftp= t2;
    return y;
}

cnode* newnode(int x)
{
    cnode* temp= new cnode;
    temp->value= x;
    temp->p= rand()%100;
    temp->leftp=NULL;
    temp->rightp= NULL;
    return temp;
}

cnode* search(cnode* root, int value)
{
    if(root==NULL || root->value==value)
    {
        return root;
    }

    if(root->value>value)
    {
        return search(root->leftp, value);
    }
    if(root->value<value)
    {
        return search(root->rightp, value);
    }
}

cnode* insert(cnode* root, int value)
{
    if(root==NULL)
    {
        return newnode(value);
    }

    if(root->value>=value)
    {
        root->leftp= insert(root->leftp, value);
        if(root->leftp->p>root->p)
        {
            root= rightprotate(root);
        }
    }
    else if(root->value<value)
    {
        root->rightp= insert(root->rightp, value);
        if(root->rightp->p>root->p)
        {
            root= leftprotate(root);
        }
    }

    return root;
}

cnode* deletenode(cnode* root, int value)
{
    if(root==NULL)
    {
        return root;
    }
    //If value is not equal to root's value, we check in its rightp or leftp subtree//
    if(root->value>value)
    {
        root->leftp= deletenode(root->leftp, value);
    }
    else if(root->value<value)
    {
        root->rightp= deletenode(root->rightp, value);
    }
    else if(root->value==value)
    {
        if(root->leftp==NULL)
        {
            cnode* temp= root->rightp;
            delete(root);
            root= temp;
        }
        else if(root->rightp==NULL)
        {
            cnode* temp= root->leftp;
            delete(root);
            root= temp;
        }
        else if(root->leftp!=NULL && root->rightp!=NULL)
        {
            if(root->leftp->p>root->rightp->p)
            {
                root= rightprotate(root);
                root->rightp= deletenode(root->rightp, value);
            }
            else if(root->rightp->p>root->leftp->p)
            {
                root= leftprotate(root);
                root->leftp= deletenode(root->leftp, value);
            }
        }
    }
    return root;
}

void inorder(cnode* root)
{
    if (root!=NULL)
    {
        inorder(root->leftp);
        cout << "value: "<< root->value << " | Priority: "
            << root->p;
        if (root->leftp)
            cout << " | leftp child: " << root->leftp->value;
        if (root->rightp)
            cout << " | rightp child: " << root->rightp->value;
        cout << endl;
        inorder(root->rightp);
    }
}
int main()
{

    struct cnode *root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 120);
    root = insert(root, 102);

    cout << "Inorder traversal of the given tree \n";
    inorder(root);

    root = deletenode(root, 20);
    cout << "Inorder traversal of the modified tree after deletion of 20 \n";
    inorder(root);

    root = deletenode(root, 30);
    cout << "Inorder traversal of the modified tree after deletion of 30 \n";
    inorder(root);

    root = deletenode(root, 50);
    cout << "Inorder traversal of the modified tree after deletion of 50\n";
    inorder(root);

    cnode *res = search(root, 50);
    if(res==NULL)
    {
        cout<<"50 is not Found!!!" <<endl;
    }
    else
    {
        cout<< "50 is found!!!" <<endl;
    }
    return 0;
}