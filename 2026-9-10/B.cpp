#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=2e6+10,S=1<<20;
signed n,a[N],vis[N],l[N],r[N],head[N],tail[N],nxt[N],ql[N],qr[N],tot;
char buf[S];
signed p1,p2;
inline char gc()
{
    if(p1==p2)p2=fread(buf,1,S,stdin),p1=0;
    if(p1==p2)return 0;
    return buf[p1++];
}
inline signed read()
{
    signed x=0;
    char c=gc();
    while(c<'0'||c>'9')c=gc();
    while(c>='0'&&c<='9')x=x*10+c-'0',c=gc();
    return x;
}
void solve()
{
    n=read();
    tot=0;
    for(int i=1;i<=n;i++)vis[i]=head[i]=tail[i]=0;
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        a[i]=read();
        if(!vis[a[i]])cnt++,vis[a[i]]=1;
    }
    for(int i=1;i<=n;i++)
    {
        int j=i;
        while(j<=n&&a[j]==a[i])j++;
        j--;
        ql[++tot]=i;
        qr[tot]=j;
        nxt[tot]=0;
        if(!head[a[i]])head[a[i]]=tot;
        else nxt[tail[a[i]]]=tot;
        tail[a[i]]=tot;
        i=j;
    }
    int p=1;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(i>1&&a[i]<=a[i-1])p=i;
        l[i]=p;
        if(cnt>=3)ans=max(ans,i-l[i]+1);
    }
    p=n;
    for(int i=n;i>=1;i--)
    {
        if(i<n&&a[i]>=a[i+1])p=i;
        r[i]=p;
    }
    for(int i=1;i<=n;i++)
    {
        if(!head[i])continue;
        int now=0,las=0;
        for(int j=head[i];j;las=j,j=nxt[j])
        {
            int x=ql[j],y=qr[j];
            if(!las&&x>1)now=x-l[x-1];
            if(las&&r[qr[las]+1]<x-1)
                now=min(x-l[x-1],x-qr[las]-1);
            ans=max(ans,now);
            if(x==1||y==n||a[x-1]>=a[y+1])now=0;
            else now+=y-x+1;
            if(y==n)continue;
            if(nxt[j])now+=min(r[y+1]-y,ql[nxt[j]]-y-1);
            else now+=r[y+1]-y;
            ans=max(ans,now);
        }
    }
    printf("%lld\n",(long long)(ans>=2?ans:0));
}
signed main()
{
    int t=read();
    while(t--)solve();
    return 0;
}
