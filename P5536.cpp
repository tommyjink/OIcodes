#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+100;
int n,k,in[N],inn[N],dep[N];
int head[N],tot=0;
struct node
{
    int from,to,next;
}e[N*2];
void add(int x,int y)
{
    e[++tot]=(node){x,y,head[x]};
    head[x]=tot;
}
int topo(int k)
{
    for(int i=1;i<=n;i++)
        in[i]=inn[i],dep[i]=0;
    int res=0;
    queue<int> q;
    for(int i=1;i<=n;i++)
        if(in[i]==1)q.push(i);
    while(!q.empty())
    {
        int t=q.front();q.pop();
        if(dep[t]==k)continue;
        res++;
        for(int i=head[t];i;i=e[i].next)
        {
            int v=e[i].to;
            if(--in[v]==1)
                q.push(v),dep[v]=dep[t]+1;
        }
    }
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>k;
    for(int i=1;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        inn[x]++,inn[y]++;
        add(x,y),add(y,x);
    }
    int l=0,r=n;
    while(l<r)
    {
        int mid=(l+r)>>1;
        int res=n-topo(mid);
        if(res>k)l=mid+1;
        else r=mid;
    }
    cout<<l<<endl;
    return 0;
}