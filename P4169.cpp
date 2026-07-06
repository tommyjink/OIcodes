#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10,INF=1e16;
int n,m,cnt=0,tot=0,ans[N];
struct node{int x,y,type,id,ans;}tq[N],q[N],b[N];
bool cmpx(node x,node y){return x.x==y.x?x.y<y.y:x.x<y.x;}
struct BIT
{
    int t[2*N+10];
    inline int lowbit(int x){return x&-x;}
    void init(){for(int i=0;i<2*N;i++)t[i]=-INF;}
    void upd(int x){for(int i=x+N;i<2*N;i+=lowbit(i))t[i]=-INF;}
    void add(int x,int d){for(int i=x+N;i<2*N;i+=lowbit(i))t[i]=max(t[i],d);}
    int query(int x){int res=-INF;for(int i=x+N;i;i-=lowbit(i))res=max(res,t[i]);return res;}
}t;
void CDQ(int l,int r)
{
    if(l==r)return;
    int mid=(l+r)>>1,i=l;
    CDQ(l,mid),CDQ(mid+1,r);
    for(int j=mid+1;j<=r;j++)
    {
        while(i<=mid&&q[i].x<=q[j].x)
        {
            if(q[i].type==1)t.add(q[i].y,q[i].x+q[i].y);
            i++;
        }
        if(q[j].type==2)
            ans[q[j].id]=min(ans[q[j].id],q[j].x+q[j].y-t.query(q[j].y));
    }
    for(int j=l;j<i;j++)t.upd(q[j].y);
    int p1=l,p2=mid+1,now=l;
    while(p1<=mid&&p2<=r)
    {
        if(cmpx(q[p1],q[p2]))b[now++]=q[p1],p1++;
        else b[now++]=q[p2],p2++;
    }
    while(p1<=mid)b[now++]=q[p1],p1++;
    while(p2<=r)b[now++]=q[p2],p2++;
    for(int i=l;i<=r;i++)q[i]=b[i];
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        int x,y;
        cin>>x>>y;
        tq[++cnt]={x,y,1};
    }
    for(int i=1;i<=m;i++)
    {
        int op,x,y;
        cin>>op>>x>>y;
        if(op==1)tq[++cnt]={x,y,1};
        if(op==2)tq[++cnt]={x,y,2,++tot};
    }
    for(int i=1;i<=tot;i++)ans[i]=INF;
    for(int i=1;i<=cnt;i++)q[i]=tq[i];
    t.init();
    CDQ(1,cnt);
    for(int i=1;i<=cnt;i++)q[i]=tq[i],q[i].x=-q[i].x;
    t.init();
    CDQ(1,cnt);
    for(int i=1;i<=cnt;i++)q[i]=tq[i],q[i].y=-q[i].y;
    t.init();
    CDQ(1,cnt);
    for(int i=1;i<=cnt;i++)q[i]=tq[i],q[i].x=-q[i].x,q[i].y=-q[i].y;
    t.init();
    CDQ(1,cnt);
    for(int i=1;i<=tot;i++)cout<<ans[i]<<endl;
    return 0;
}