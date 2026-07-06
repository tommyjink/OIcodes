#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=250010;
struct node{int x,y;}a[N],up[N],dw[N],stk[N];
int n,k,m,st[N],ed[N];
int cross(node a,node b,node c)
{
    return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
}
int dis(node a,node b)
{
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
int diam(int l,int r)
{
    int L=st[l],R=ed[r];
    if(L==R)return 0;
    if(L+1==R)return dis(a[L],a[R]);
    int t1=0,t2=0;
    for(int i=L;i<=R;i++)
    {
        while(t1>=2&&cross(up[t1-2],up[t1-1],a[i])>=0)t1--;
        up[t1++]=a[i];
        while(t2>=2&&cross(dw[t2-2],dw[t2-1],a[i])<=0)t2--;
        dw[t2++]=a[i];
    }
    int tot=0;
    for(int i=0;i<t2;i++)stk[tot++]=dw[i];
    for(int i=t1-2;i>=1;i--)stk[tot++]=up[i];
    if(tot<=2)return dis(stk[0],stk[tot-1]);
    int j=1,ans=0;
    for(int i=0;i<tot;i++)
    {
        int nxt=(i+1==tot?0:i+1);
        while(cross(stk[i],stk[nxt],stk[(j+1==tot?0:j+1)])>cross(stk[i],stk[nxt],stk[j]))
            j=(j+1==tot?0:j+1);
        ans=max(ans,max(dis(stk[i],stk[j]),dis(stk[nxt],stk[j])));
    }
    return ans;
}
int check(int x)
{
    int l=1,cnt=0;
    while(l<=m)
    {
        cnt++;
        if(cnt>k||diam(l,l)>x)return 0;
        int r=l,s=1;
        while(r+s<=m&&diam(l,r+s)<=x)
            r+=s,s<<=1;
        int L=r+1,R=min(m,r+s),res=r;
        while(L<=R)
        {
            int mid=(L+R)>>1;
            if(diam(l,mid)<=x)
                res=mid,L=mid+1;
            else R=mid-1;
        }
        l=res+1;
    }
    return 1;
}
void solve()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i].x>>a[i].y;
    sort(a+1,a+n+1,[](node A,node B){return A.x==B.x?A.y<B.y:A.x<B.x;});
    m=0;
    for(int i=1;i<=n;i++)
    {
        if(i==1||a[i].x!=a[i-1].x)st[++m]=i,ed[m]=i;
        else ed[m]=i;
    }
    int l=0,r=2e18,ans=2e18;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(check(mid))ans=mid,r=mid-1;
        else l=mid+1;
    }
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
