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

    ll key;
    Node* leftChild;
    Node* rightChild;
    Node* Parent;

};

struct Node* CreateNode (){

	struct Node * newNode =(struct Node*)malloc(sizeof(struct Node));
	return newNode;
}
void Insert (struct Node* root, ll x, bool LRFlag){

    struct Node* temp = CreateNode();

    temp->key=x;
    if(LRFlag){

        temp->rightChild = root->rightChild;
        temp->Parent = root;
        root->rightChild->Parent = temp;
        temp->leftChild = NULL;

        root->rightChild = temp;

    }

    else {

        temp->leftChild = root->leftChild;
        temp->Parent = root;
        root->leftChild->Parent = temp;
        temp->rightChild = NULL;

        root->leftChild = temp;

    }

    return;

}

void Delete (struct Node* root ){



}



int main()
{
      ios::sync_with_stdio(0);
      cin.tie(0);
      cout.tie(0);

      ll q=1;
      //cin>>q;
      while(q--)
      {
            ll n;
            cin>>n;

            ll a[n];


            int flag=0;
            REP(i,0,n)
            {
                  cin>>a[i];
            }

      }

return 0;
}
