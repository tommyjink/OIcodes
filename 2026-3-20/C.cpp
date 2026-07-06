#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=2e5+10;
int T,n,k,a[N],fl[N],fr[N],st[N],fa[N],cv[N],ans[N];
struct node
{
    int x,y,c;
}q[N];
bool cmp(node a,node b)
{
    return a.x<b.x;
}
struct cmp2
{
    bool operator()(node a,node b)
    {
        return a.y>b.y;
    }
};
int find(int x)
{
    return fa[x]==x?x:fa[x]=find(fa[x]);
}
bool check(int M,int op)
{
    int len=M+1,cnt=0;
    for(int i=1;i<=k;i++)
    {
        if(fl[i]!=-1)
        {
            if(fr[i]-fl[i]+1>len)return false;
            q[++cnt]={max(1LL,fr[i]-len+1),fl[i],i};
        }
        else
        {
            q[++cnt]={1,n,i};
        }
    }
    sort(q+1,q+1+cnt,cmp);
    int now=1,j=1;
    priority_queue<node,vector<node>,cmp2>pq;
    for(int i=1;i<=k;i++)st[i]=-1;
    while(now<=n)
    {
        while(j<=cnt&&q[j].x<=now)pq.push(q[j++]);
        if(pq.empty())return false;
        node u=pq.top();
        pq.pop();
        if(u.y>=now)
        {
            st[u.c]=now;
            now+=len;
        }
        else
        {
            if(u.y+len>now)
            {
                st[u.c]=u.y;
                now=u.y+len;
            }
            else st[u.c]=u.y;
        }
    }
    if(op)
    {
        while(!pq.empty())
        {
            node u=pq.top();
            pq.pop();
            st[u.c]=u.x; 
        }
        while(j<=cnt)
        {
            node u=q[j++];
            st[u.c]=u.x; 
        }
        
        for(int i=1;i<=n+1;i++)fa[i]=i,cv[i]=0;
        for(int i=1;i<=k;i++)
        {
            int L=st[i],R=min(n,L+len-1);
            for(int p=find(L);p<=R;p=find(p))
            {
                cv[p]=i;
                fa[p]=p+1;
            }
        }
        for(int i=1;i<=n;i++)
            ans[i]=a[i]==0?cv[i]:a[i];
    }
    return true;
}
void solve()
{
    cin>>n>>k;
    for(int i=1;i<=k;i++)fl[i]=fr[i]=-1;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i])
        {
            if(fl[a[i]]==-1)fl[a[i]]=i;
            fr[a[i]]=i;
        }
    }
    int l=0,r=n-1,res=n-1;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(check(mid,0))
        {
            res=mid;
            r=mid-1;
        }
        else l=mid+1;
    }
    check(res,1);
    for(int i=1;i<=n;i++)
        cout<<ans[i]<<" ";
    cout<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>T;
    while(T--)solve();
    return 0;
}