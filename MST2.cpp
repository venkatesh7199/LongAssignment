#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define MP make_pair
#define PB push_back
#define N 100001
#define HOLE 1000000007

vector<pair<int,pair<int,int>>> prim(vector<pair<int,int>> V[],int n){

    vector<pair<int,pair<int,int>>> MST;
    priority_queue<pair<int,pair<int,int>>> precedence;
    bool visited[n+1]={};
    visited[1]=1;
    for(auto it:V[1]){
        precedence.push(MP(-it.second,MP(1,it.first)));
    }

    while(!precedence.empty()){
        pair<int,pair<int,int>> E = precedence.top();
        precedence.pop();
        if(visited[(E.second).second])
            continue;
        visited[(E.second).second]=1;
        E.first=(-E.first);
        MST.PB(E);
        for(auto it:V[(E.second).second])
        {
            precedence.push(MP(-it.second,MP((E.second).second,it.first)));
        }
    }

    return MST;
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> ad[n+1];
    REP(i,0,m){
    
        int u,v,w;
        cin>>u>>v>>w;
        ad[u].PB(MP(v,w));
        ad[v].PB(MP(u,w));
    }

    auto v=prim(ad,n);
    long long ans=0;
    for(auto x:v)
    {
        ans+=x.first;
    }
    cout<<ans;

    return 0;
}