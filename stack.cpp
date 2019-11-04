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

typedef struct {

      ll* stk;
      ll numberOfElementsInStack=0;
      ll sizeOfStack=1;

} stacks;

bool isFull(stacks s){
    if(s.sizeOfStack == s.numberOfElementsInStack ){
        return true;
    }

    return false;
}

void push (ll x, stacks* s){

    if(isFull(*s)){

        ll *temp2=s->stk;
        ll * temp=(ll *)malloc(2*s->sizeOfStack*sizeof(ll));
        for(ll i=0; i<s->sizeOfStack; i++){

            temp[i]=s->stk[i];

        }

        s->stk=temp;
        s->sizeOfStack*=2;
        s->stk[s->numberOfElementsInStack]=x;
        s->numberOfElementsInStack++;
        free(temp2);

    } else{

        s->stk[s->numberOfElementsInStack]=x;
        s->numberOfElementsInStack++;

    }


}

ll top(stacks s){

    return s.stk[s.numberOfElementsInStack-1];

}

ll pop(stacks* s){

    s->numberOfElementsInStack--;
    return s->stk[s->numberOfElementsInStack];

}

int main()
{
      ios::sync_with_stdio(0);
      cin.tie(0);
      cout.tie(0);


      //cin>>q;
      stacks s1;
      push(1, &s1);
      push(2, &s1);
      push(8, &s1);
      push(7, &s1);
      push(6, &s1);
      push(5, &s1);
            push(6, &s1);
      push(6, &s1);
      push(6, &s1);
      pop(&s1);
      pop(&s1);
      pop(&s1);



      cout<<s1.sizeOfStack<<" "<<s1.numberOfElementsInStack<<endl;
      cout<<top(s1)<<endl;

    return 0;


}
