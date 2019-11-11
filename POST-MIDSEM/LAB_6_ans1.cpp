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
#define SIZE 100

using namespace std;

int main(){
    map<string,int> mp;
    vector<string> v;
    lli n;
    cin>>n;
    lli i;
    fo(i,n){
        string s,t; cin>>s;
        t=s; reverse(t.begin(),t.end());
        if(t!=s) {mp.insert({s,i});
        v.pb(t);}
    }
    fo(i,v.size()){
        auto it = mp.find(v[i]);
        if(it!=mp.end()) {cout<<"YES\n"; return 0;}
    }
    cout<<"NO\n";
    return 0;

}