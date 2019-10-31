#include<bits/stdc++.h>
#define gc getchar_unlocked

#define Fo(i,k,n) for(i=k;i<n;i++)
#define lli long long int
#define pii pair<int,int>
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define ll long long
 
using namespace std;

void addedge(vector<lli> adj[],lli u,lli v){
    adj[u].pb(v);
    adj[v].pb(u);
    
}

bool isbip(vector<lli> adj[],int v,vector<bool>& visited,vector<lli>& color){
    for(lli u : adj[v]){
        if(visited[u]==false){
            visited[u]=true;
            color[u]=!color[v];
            if(!isbip(adj,u,visited,color))
            return false;
        }
        else if(color[u]==color[v])
        return false;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lli n,m; cin>>n>>m;
    lli i;
    lli j=n;
    vector<lli> adj[10000000];
    vector<bool> visited(10000000);
    vector<lli> color(10000000);
    for(i=0;i<m;i++){
        lli a,b,w;
        cin>>a>>b>>w;
        if(w%2==1){
            addedge(adj,a,b);
        }
        else{
           j++;
           addedge(adj,a,j);
           addedge(adj,b,j);
        }
    }
    visited[1]=true;
    color[1]=0;
    if(isbip(adj,1,visited,color)) cout<<"NO";
    else cout<<"YES";
    return 0;}
