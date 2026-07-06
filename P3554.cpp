#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,cnt[N],num[N];
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
void dfs(int x,int fa,int mid)
{
    num[x]=cnt[x]=0;
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(v==fa)continue;
        cnt[x]++;
        dfs(v,x,mid);
        num[x]+=num[v];
    }
    num[x]+=cnt[x]-mid;
    num[x]=max(0ll,num[x]);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n-1;i++)
    {
        int x,y;
        cin>>x>>y;
        add(x,y);
        add(y,x);
    }
    int l=0,r=1e9;
    while(l<r)
    {
        int mid=(l+r)>>1;
        dfs(1,0,mid);
        if(!num[1])r=mid;
        else l=mid+1;
    }
    cout<<l<<endl;
    return 0;
}