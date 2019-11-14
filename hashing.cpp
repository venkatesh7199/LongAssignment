#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define MP make_pair
#define PB push_back
#define N 100001
#define HOLE 1000000007

struct bucket
{
    list <int> a;
};

struct bucket table[N];
int buckets;

int hashfunction(int x)
{
    return x%buckets;
}

void insert(int x)
{
    int index= hashfunction(x);
    table[index].a.push_back(x);
}

void deleteitem(int x)
{
    int index= hashfunction(x);
    int f=0;
    for(auto i: table[index].a)
    {
        if(i==x)
        {
            f=1;
            break;
        }
    }
    if(f)
    {
        table[index].a.remove(x);
    }
}

void display_hashtable()
{
    for(int i=0; i<buckets; i++)
    {
        cout<<"Bucket " <<i <<" :";
        for(auto ass: table[i].a)
        {
            cout<< ass <<"| ";
        }
        cout<<endl;
    }
}


int main()
{
    cin>>buckets;
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        int x;
        cin>> x;
        insert(x);
    }
    cout<<"After insertion: " <<endl;
    display_hashtable();
    int h;
    cin>> h;
    while(h--)
    {
        int x;
        cin>>x;
        deleteitem(x);
    }
    cout<< "After deletion: " <<endl;
    display_hashtable();
}