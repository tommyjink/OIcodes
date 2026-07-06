#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
string s,t;
int n,m,nxt[N];
signed main()
{
    cin>>s>>t;
    n=s.length();
    m=t.length();
    s=" "+s;
    t=" "+t;
    for(int i=2,j=0;i<=m;i++)
    {
        while(j&&t[j+1]!=t[i])j=nxt[j];
        if(t[j+1]==t[i])j++;
        nxt[i]=j;
    }
    for(int i=1,j=0;i<=n;i++)
    {
        // cout<<i<<endl;
        while(j&&t[j+1]!=s[i])j=nxt[j];
        if(t[j+1]==s[i])j++;
        if(j==m)cout<<i-m+1<<endl,j=nxt[j];
    }
    for(int i=1;i<=m;i++)cout<<nxt[i]<<" ";
    return 0;
}