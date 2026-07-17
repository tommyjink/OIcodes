#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=2e5+10;
int n,m,l[N],r[N],nxt[N][2],pre[N][2],lim[N];
int a[N],b[N],ans[N];
string s,t;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>s>>t;
    n=s.length(),m=t.length();
    s=" "+s,t=" "+t;
    for(int i=1;i<=n;i++)
        if(s[i]=='A')a[i]=1;
    for(int i=1;i<=m;i++)
        if(t[i]=='A')b[i]=1;
    for(int i=n;i>=1;i--)
    {
        if(i==n)nxt[i][0]=nxt[i][1]=n+1;
        else nxt[i][0]=nxt[i+1][0],nxt[i][1]=nxt[i+1][1];
        nxt[i][a[i]]=i;
    }
    for(int i=1;i<=n;i++)
    {
        if(i==1)pre[i][0]=pre[i][1]=0;
        else pre[i][0]=pre[i-1][0],pre[i][1]=pre[i-1][1];
        pre[i][a[i]]=i;
    }
    for(int i=1;i<=n;i++)
        lim[i]=nxt[i][a[i]^1];
    lim[n+1]=n+1;
    nxt[n+1][0]=nxt[n+1][1]=n+1;
    for(int i=1;i<=m;i++)
    {
        l[i]=l[i-1]+1;
        r[i]=min(n,lim[r[i-1]+1]);
        l[i]=nxt[l[i]][b[i]];
        r[i]=pre[r[i]][b[i]];
        if(l[i]>r[i])cout<<"NO"<<endl,exit(0);
    }
    if(lim[r[m]+1]<n+1)cout<<"NO"<<endl,exit(0);
    cout<<"YES"<<endl;
    ans[m+1]=n+1;
    for(int i=m;i>=1;i--)
        ans[i]=pre[min(ans[i+1]-1,r[i])][b[i]];
    for(int i=1;i<=m;i++)
        cout<<ans[i]<<" ";
    return 0;
}