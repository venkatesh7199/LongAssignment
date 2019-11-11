#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define MP make_pair
#define PB push_back
#define N 100001
#define HOLE 1000000007
#define INF 1<<30-1

int** floyd_warshall(vector<pair<int,int>> V[],int n)
{

    int (*distance)[n+1]=(int (*)[n+1])(malloc(sizeof(int [n+1][n+1])));
    for(int root=1;root<=n;root++)
    {
        for(int node=1;node<=n;node++)
        {
            distance[root][node]=INF;
        }
        for(auto it:V[root])
        {
            distance[root][it.first]=it.second;
        }
        distance[root][root]=0;
    }
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(distance[i][k]+distance[k][j]<distance[i][j])
                {
                    distance[i][j]=distance[i][k]+distance[k][j];
                }
            }
        }
    }
    for(int root=1;root<=n;root++)
    {
        for(int node=1;node<=n;node++)
        {
            if(distance[root][node]==INF) distance[root][node]=-1;
        }
    }

    return (int**)distance;
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> ad[n+1];
    REP(i,0,m){
        int u,v,w;
        cin>>u>>v>>w;
        ad[u].PB(make_pair(v,w));
    }
    int (*d)[n+1];
    d=(int (*)[n+1])(floyd_warshall(ad,n));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<d[i][j]<<' ';
        }
        cout<<endl;;
    }
    free(d);

    return 0;
}