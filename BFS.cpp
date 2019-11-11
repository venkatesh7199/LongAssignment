#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define REP(i,a,b) for(ll i=a;i<b;i++)

vector<int> bfs(int root,vector<int> V[],int n)
{
    bool visited[n+1]={};

    vector<int> bfs_order;

    queue<int> CurrQ;    

    CurrQ.push(root);

    while(!CurrQ.empty())
    {
        root = CurrQ.front();
        CurrQ.pop();

        if(visited[root])
            continue;
        visited[root]=1;
        bfs_order.push_back(root);

        for(auto node:V[root])
        {
            CurrQ.push(node);
        }
    }

    return bfs_order;
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> adjacency[n+1];
    REP(i,0,m)
    {
        int u,v;
        cin>>u>>v;
        adjacency[u].push_back(v);
        adjacency[v].push_back(u);
        
    }
    vector<int> v=bfs(1,adjacency,n);
    for(auto x:v)
    {
        cout<<x<<' ';
    }


    return 0;
}