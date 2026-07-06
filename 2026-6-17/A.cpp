#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=2e5+20;
int t,o,n,s[N],head[N],nxt[N*2],to[N*2],tot;
int d[N],siz[N],ms,ms2;
int f1,f2,r1,r2;
int s1[N],t1,s2[N],t2;
int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9')
    {
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')
    {
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*f;
}
int reac()
{
    char ch=getchar();
    while(ch<'0'||ch>'9')
        ch=getchar();
    return ch-'0';
}
void add(int x,int y)
{
    d[x]++;
    d[y]++;
    nxt[++tot]=head[x];
    to[tot]=y;
    head[x]=tot;
}
void dfs(int x,int fa)
{
    siz[x]=1;
    int mx=0;
    for(int i=head[x];i;i=nxt[i])
    {
        int y=to[i];
        if(y==fa)continue;
        dfs(y,x);
        mx=max(mx,siz[y]);
        siz[x]+=siz[y];
    }
    ms=max(ms,min(siz[x],n-siz[x]));
    if(d[x]>=6)
    {
        mx=max(mx,n-siz[x]);
        ms2=max(ms2,n-mx);
    }
}
void dfs2(int x,int fa)
{
    int sn=0;
    for(int i=head[x];i;i=nxt[i])
    {
        int y=to[i];
        if(y==fa)continue;
        dfs2(y,x);
        if(siz[y]>siz[sn])sn=y;
    }
    if(!f2)
    {
        if(siz[x]==ms&&d[fa]>=6)
        {
            r1=fa;
            r2=x;
        }
        if(n-siz[x]==ms&&d[x]>=6)
        {
            r1=x;
            r2=fa;
        }
    }
    if(!f1&&d[x]>=6)
    {
        int ss=siz[sn];
        if(n-siz[x]>ss)
        {
            ss=n-siz[x];
            sn=fa;
        }
        if(ms2==n-ss)
        {
            r1=x;
            r2=sn;
        }
    }
}
void dfs3(int x,int fa)
{
    s1[++t1]=x;
    for(int i=head[x];i;i=nxt[i])
    {
        int y=to[i];
        if(y!=fa)dfs3(y,x);
    }
}
void dfs4(int x,int fa)
{
    s2[++t2]=x;
    for(int i=head[x];i;i=nxt[i])
    {
        int y=to[i];
        if(y!=fa)dfs4(y,x);
    }
}
void solve()
{
    n=read();
    for(int i=1;i<=n;i++)
        head[i]=d[i]=0;
    tot=0;
    for(int i=1;i<n;i++)
    {
        int x=read(),y=read();
        add(x,y);
        add(y,x);
    }
    int flg=1,md=0;
    for(int i=1;i<=n;i++)
    {
        md=max(md,d[i]);
        s[i]=reac();
        if(i&1)flg&=(s[i]==1);
        if(i==2)flg&=(s[i]==0);
    }
    if(!flg)
    {
        cout<<"NO"<<endl;
        return;
    }
    ms=0;
    ms2=1;
    dfs(1,0);
    f1=f2=0;
    for(int i=2*ms+2;i<=n;i+=2)
    {
        flg&=(s[i]==1);
        f1=1;
    }
    for(int i=2*ms2;i<=n;i+=2)
    {
        flg&=(s[i]==0);
        f2=1;
    }
    if(!flg)
    {
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
    if(md<=4)
    {
        for(int i=1;i<=n;i++)
            cout<<i<<" ";
        cout<<endl;
        return;
    }
    r1=r2=0;
    t1=t2=0;
    dfs2(1,0);
    dfs3(r1,r2);
    dfs4(r2,r1);
    for(int i=1;i*2<=t1;i++)
        swap(s1[i],s1[t1-i+1]);
    int p=s1[1];
    for(int i=1;i<t1-1;i++)
        s1[i]=s1[i+1];
    s1[t1-1]=p;
    for(int i=2;i<=2*min(ms,ms2-1);i+=2)
    {
        if(s[i]==s[i-2])
        {
            cout<<s1[t1--]<<" ";
            cout<<s2[t2--]<<" ";
        }
        else if(s[i]==1)
        {
            cout<<s1[t1--]<<" ";
            cout<<s1[t1--]<<" ";
        }
        else
        {
            cout<<s2[t2--]<<" ";
            cout<<s2[t2--]<<" ";
        }
    }
    while(t1)cout<<s1[t1--]<<" ";
    while(t2)cout<<s2[t2--]<<" ";
    cout<<endl;
}
signed main()
{
    t=read();
    o=read();
    while(t--)solve();
    return 0;
}
