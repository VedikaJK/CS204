#include<bits/stdc++.h>
using namespace std;
#define lli long long int
void addedge(vector<lli> adj[], lli u,lli v){
    adj[u].push_back(v);
    adj[v].push_back(u);
    
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

int main()
{
    lli n,m;
    cin>>n>>m;
    vector<lli> adj[n+1];
    vector<bool> visited(n+1);
    vector<lli> color(n+1);
    for(lli i=0;i<m;i++){
        lli a,b;
        cin>>a>>b;
        addedge(adj,a,b);

    }
    visited[1]=true;
    color[1]=0;
    if(isbip(adj,1,visited,color))
    cout<<"YES\n";
    else
    cout<<"NO\n";
    return 0;
}