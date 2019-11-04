#include<bits/stdc++.h>
#define gc getchar_unlocked
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;i<n;i++)
#define lli long long int
#define pii pair<int,int>
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define ll long long
#define SIZE 100001
 
using namespace std;

lli parent[SIZE],rankv[SIZE];
void makeSet(lli  x)
{
    parent[x]=x;
    rankv[x]=1;
}
 
lli  findset(lli  x)
{
    if (x==parent[x]) return x;
    return parent[x]=findset(parent[x]);
}
 
void Union (lli  a, lli  b)
{
    a=findset(a);
    b=findset(b);
    if (a!=b)
    {
        if (rankv[a]<rankv[b]) swap(a,b);
        parent[b]=a;
        rankv[a]+=rankv[b];
    }
}

int main(){
    vector<pair<lli,pair<lli,lli>>> vec;
    lli i,e,v;
    cin>>v>>e;
    lli a,b,w;
    fo(i,v) makeSet(i);
    fo(i,e){
        
        cin>>a>>b>>w;
        vec.push_back(make_pair(w,make_pair(a,b)));
    }
    sort(vec.begin(),vec.end());
    lli ans=1;
    for(lli z=e-1;z>=0;z--){
        w=vec[z].first;
        a=vec[z].second.first;
        b=vec[z].second.second;
        if(findset(a)!=findset(b)){
            ans=((ans%mod)*(w%mod))%mod;
            Union (a,b);
        }
    }
    cout<<ans<<"\n";
}