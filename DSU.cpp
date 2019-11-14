#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define MP make_pair
#define PB push_back
#define N 100001
#define HOLE 1000000007

ll fn(ll x,ll rn[])
{
      if(rn[x]==x) return x;
      else return rn[x]=fn(rn[x],rn);
}

void un(ll x,ll y,ll rn[],ll sz[])
{
      x=fn(x,rn);
      y=fn(y,rn);
      if(x==y) return;
      if(sz[x]<sz[y]) swap(x,y);
      sz[x]+=sz[y];
      rn[y]=x;
      return;
}

int main()
{
    ll n,m;
    cin>>n>>m;
    ll j;

    ll rn[n];
    ll sz[n];

    ll arr[n]

    REP(i,0,n+1){
        rn[i]=i;
        sz[i]=1;
    }

    REP(i,0,n){

        cin>>j;
        arr[i]=j;

    }

    ll e1,e2;

    REP(i,0,m){

        cin>>e1>>e2;

        if(fn(e1) == fn(e2) )
            continue;
        else{

             un (e1,e2, rn, sz );

        }

    }

    return 0;
}