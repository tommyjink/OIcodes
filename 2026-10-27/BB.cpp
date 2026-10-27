#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=2e5+10;
int n,m,a[N],pos[N],pre[N],nxt[N],head[N],tail[N],tag[N];
int c[15],d[5],e[15];
pii b[N];
struct node
{
    int val,x,y,z,id,tag;
    bool operator<(const node &b)const
    {
        if(val!=b.val)return val>b.val;
        if(x!=b.x)return x>b.x;
        if(y!=b.y)return y>b.y;
        return z>b.z;
    }
};
priority_queue<node> q;
void upd(int g)
{
    tag[g]++;
    int cnt=0,x=g,flag=0;
    node ans={};
    for(int len=1;len<=3&&x;len++,x=nxt[x])
    {
        for(int j=head[x];j<=tail[x]&&j<head[x]+3;j++)
            c[++cnt]=b[j].second;
        if(cnt<3)continue;
        sort(c+1,c+cnt+1);
        int i=c[1],j=c[2],k=c[3];
        int val=max({a[i],a[j],a[k]})-min({a[i],a[j],a[k]});
        node now={val,i,j,k,g,tag[g]};
        if(!flag||ans<now)ans=now,flag=1;
    }
    if(flag)q.push(ans);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i],b[i]={a[i],i};
    sort(b+1,b+n+1);
    for(int i=1;i<=n;i++)
    {
        if(i==1||b[i].first!=b[i-1].first)head[++m]=i;
        tail[m]=i;
        pos[b[i].second]=m;
    }
    for(int i=1;i<=m;i++)pre[i]=i-1,nxt[i]=i+1;
    nxt[m]=0;
    for(int i=1;i<=m;i++)upd(i);
    for(int t=1;t<=n/3;t++)
    {
        while(!q.empty()&&q.top().tag!=tag[q.top().id])q.pop();
        node now=q.top();q.pop();
        cout<<now.x<<" "<<now.y<<" "<<now.z<<endl;
        d[1]=pos[now.x],d[2]=pos[now.y],d[3]=pos[now.z];
        sort(d+1,d+4);
        int cnt=unique(d+1,d+4)-d-1,tot=0;
        for(int i=1;i<=cnt;i++)
        {
            int x=d[i];
            for(int j=0;j<3&&x;j++,x=pre[x])e[++tot]=x;
        }
        sort(e+1,e+tot+1);
        tot=unique(e+1,e+tot+1)-e-1;
        head[pos[now.x]]++;
        head[pos[now.y]]++;
        head[pos[now.z]]++;
        for(int i=1;i<=cnt;i++)
        {
            int x=d[i];
            if(head[x]>tail[x])
            {
                int l=pre[x],r=nxt[x];
                if(l)nxt[l]=r;
                if(r)pre[r]=l;
            }
        }
        for(int i=1;i<=tot;i++)
        {
            int x=e[i];
            if(head[x]<=tail[x])upd(x);
            else tag[x]++;
        }
    }
    return 0;
}
