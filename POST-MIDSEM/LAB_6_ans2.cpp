#include<bits/stdc++.h>
#define gc getchar_unlocked
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;i<n;i++)
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define lli long long int
#define pii pair<int,int>
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define ll long long
#define SIZE 100
#define M 10000019
#define num 5
using namespace std;

static bool hashingTable[num][M];
static ll pr[num];

ll ord(char c)
{
    if(c>='a'&&c<='z')
    {
        return (ll)(c-'a'+1);
    }
    else
        return (ll)(c-'A'+27);
}

ll func(string &s,ll p,ll m)
{
    ll n=s.size();
    ll r=1;
    ll ans=0;
    REP(i,0,n)
    {
        ans+=(r*ord(s[i]))%m;
        ans%=m;
        r*=p;
        r%=m;
    }
    return ans;
}

int main()
{
    pr[0]=53;
    pr[1]=2311;
    pr[2]=13331;
    pr[3]=123457;
    pr[4]=446141;
    ll n;
    cin>>n;
    vector<string> v;
    while(n--)
    {
        string s;
        cin>>s;
        string t=s;
        reverse(t.begin(),t.end());
        if(s!=t)
        {
            v.push_back(s);
            REP(j,0,num)
            {
                hashingTable[j][func(t,pr[j],M)]=true;
            }
        }
    }
    for(auto s:v)
    {
        bool flag=true;
        REP(j,0,num)
        {
            if(hashingTable[j][func(s,pr[j],M)]==false) flag=false;
        }
        if(flag==true)
        {
            cout<<"YES";
            return 0;
        }
    }
    cout<<"NO";

    return 0;
}
