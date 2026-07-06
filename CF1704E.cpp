#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10,P=998244353;
int n,m,tot=0,head[N],a[N],in[N],out[N];
struct node
{
    int to,next;
}e[N];
void add(int x,int y)
{
    e[++tot]=(node){y,head[x]};
    head[x]=tot;
}
void solve()
{
    queue<int> q;
    cin>>n>>m;
    tot=0;
    for(int i=1;i<=n;i++)
        cin>>a[i],in[i]=out[i]=head[i]=0;
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        add(x,y);
        in[y]++;
        out[x]++;
    }
    for(int i=1;i<=n;i++)
        if(a[i])q.push(i);
    for(int i=1;i<=n+1;i++)
    {
        // for(int k=1;k<=n;k++)
        //     cout<<a[k]<<" ";
        // cout<<endl;
        if(q.empty())
        {
            cout<<i-1<<endl;
            return;
        }
        int size=q.size();
        for(int j=1;j<=size;j++)
        {
            int t=q.front();q.pop();
            a[t]--;
            if(a[t])q.push(t);
            for(int k=head[t];k;k=e[k].next)
            {
                int v=e[k].to;
                a[v]++;
                if(a[v]==1)q.push(v);
            }
        }
    }
    while(!q.empty())q.pop();
    for(int i=1;i<=n;i++)
        if(!in[i])q.push(i);
    
    while(!q.empty())
    {
        int t=q.front();q.pop();
        for(int i=head[t];i;i=e[i].next)
        {
            int v=e[i].to;
            in[v]--;
            a[v]=(a[v]+a[t])%P;
            if(in[v]==0)q.push(v);
        }
    }
    int ans=-1;
    for(int i=1;i<=n;i++)
        if(out[i]==0)
            ans=max(ans,a[i]);
    // for(int i=1;i<=n;i++)
    //     cout<<a[i]<<" ";
    // cout<<endl;
    cout<<(ans+n+1)%P<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}