#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=5e5+10;
int n,q,tot;
int a[N],pos[N],k[N],x[N],ans[N];
int head[N],nxt[N],vis[N],id[N],c[N],bit[N];
void add(int x,int v)
{
    for(int i=x;i<=n;i+=i&-i)
        bit[i]+=v;
}
int ask(int x)
{
    int res=0;
    for(int i=x;i;i-=i&-i)
        res+=bit[i];
    return res;
}
void solve(int x)
{
    int p=pos[x];
    // cout<<x<<"!"<<p<<endl;
    for(int i=1;i<=n;i++)
        c[i]=bit[i]=0;
    int cnt=0;
    for(int i=1;i<p;i++)
    {
        if(a[i]>x)cnt++;
        add(a[i],1);
    }
    for(int i=p+1;i<=n;i++)
    {
        if(a[i]<x)
        {
            int t=cnt+1;
            if(t<n)c[t]++;
        }
        else cnt++;
    }
    for(int i=1;i<p;i++)
    {
        if(a[i]>x)
        {
            int t=ask(n)-ask(a[i])+1;
            if(t<n)c[t]--;
        }
    }
    for(int i=1;i<n;i++)
        c[i]+=c[i-1];
    for(int i=head[x];i;i=nxt[i])
        ans[i]=p+c[k[i]];
}
// void solve2(int x)
// {
//     int res=0,now=0;
//     for(int i=1;i<=n;i++)
//         bit[i]=0;
//     for(int i=1;i<=n;i++)
//     {
//         if(pos[i]>=now)continue;
//         add(pos[i],1);
//         if(ask(pos[i])>=ask(now))
//             now=pos[i];
//     }
//     for(int i=1;i<=n;i++)
//         res+=ask(nxt[i]);
//     for(int i=head[x];i;i=nxt[i])
//         ans[i]=res+ask(i);
// }
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("bubble.in","r",stdin);
    freopen("bubble.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        pos[a[i]]=i;
    }
    cin>>q;
    for(int i=1;i<=q;i++)
    {
        cin>>k[i]>>x[i];
        nxt[i]=head[x[i]];
        head[x[i]]=i;
        if(!vis[x[i]])
        {
            vis[x[i]]=1;
            id[++tot]=x[i];
        }
    }
    if(n<=2000||tot<=20)
    {
        for(int i=1;i<=tot;i++)
            solve(id[i]);
    }
    else
    {
        for(int i=1;i<=q;i++)
            ans[i]=x[i];
    }
    for(int i=1;i<=q;i++)
        cout<<ans[i]<<endl;
    return 0;
}
