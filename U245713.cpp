#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define lowbit(x) (x&(-x))
using namespace std;
const int N=1e6+100;
int n,m,a[N],ans[N];
struct node
{
    int l,r,x,op,id;
}q[N*2];
struct Tree
{
    int t[N];
    void init()
    {
        for(int i=1;i<=n;i++)
            t[i]=0;
    }
    void add(int x,int d)
    {
        x++;
        for(int i=x;i<N;i+=lowbit(i))
            t[i]+=d;
    }
    int sum(int x)
    {
        x++;
        int res=0;
        for(int i=x;i;i-=lowbit(i))
            res+=t[i];
        return res;
    }
}t;
bool cmp(node x,node y)
{
    return x.x<y.x;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=m;i++)
    {
        int l,r,x,y;
        cin>>l>>r>>x>>y;
        q[i]=(node){x,y,l-1,-1,i};
        q[i+m]=(node){x,y,r,1,i};
    }
    sort(q+1,q+1+2*m,cmp);
    int now=0;
    t.init();
    for(int i=1;i<=2*m;i++)
    {
        while(now<q[i].x)
        {
            now++;
            t.add(a[now],1);
        }
        ans[q[i].id]+=q[i].op*(t.sum(q[i].r)-t.sum(q[i].l-1));
    }
    for(int i=1;i<=m;i++)
        cout<<ans[i]<<endl;
    return 0;
}