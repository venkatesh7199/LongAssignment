#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define MP make_pair
#define PB push_back
#define N 100001
#define HOLE 1000000007

int ctr=-1;
int flag=0;

vector <ll> v[N];
ll marked [N]={0};
vector <ll> DFSorder ;

void dfs(ll x){

	if(marked[x])return;
	marked[x]=1;

	DFSorder.PB(x);

	REP(i,0,v[x].size()){
		dfs(v[x][i]);
	}

}


int main(){

	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n,m;
    cin>>n>>m;

    ll v1,v2;

    REP(i,0,m){

    	cin>>v1>>v2;
    	v[v1].push_back(v2);
    	v[v2].push_back(v1);

    }

    REP(i,1,n+1){
        dfs(i);
    }
   

    REP(i,0,n){
    	cout<<DFSorder[i]<<endl;
    }


return 0;
}
