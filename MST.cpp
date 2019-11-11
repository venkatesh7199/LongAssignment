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
    ll k,w,j;

    pair<ll, pair <ll,ll> > edges[m];

    ll rn[n];
    ll sz[n];

    ll sum=0;

    REP(i,0,n+1){
        rn[i]=i;
        sz[i]=1;
    }

    REP(i,0,m){

        cin>>w>>j>>k;
        edges[i]=MP(k,MP(w,j));

    }

    sort(edges, edges+m);

    REP(i,0,m){

        if(fn(edges[i].second.first,rn) == fn(edges[i].second.second,rn) )
            continue;
        else{

            sum=(sum+(edges[i].first))%HOLE;

             un (edges[i].second.first, edges[i].second.second, rn, sz );

        }

    }

    cout<<sum<<endl;


    return 0;
}

