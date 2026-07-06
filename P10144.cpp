#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=5e5+10,INF=1e18;
int n,h[N];
struct node
{
    int L[2][2],R[2][2];
    node()
    {
        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++)
                L[i][j]=INF,R[i][j]=-INF;
    }
}t[N<<2];
node up(node a,node b,int mid)
{
    node c;
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
        {
            if(a.L[i][j]>=a.R[i][j])continue;
            for(int k=0;k<2;k++)
                for(int o=0;o<2;o++)
                {
                    if(b.L[k][o]>=b.R[k][o])continue;
                    int l=max(a.L[i][j],b.L[k][o]),r=min(a.R[i][j],b.R[k][o]);
                    if(j==0&&k==0&&h[mid]>=h[mid+1])continue;
                    if(j==1&&k==1&&h[mid]<=h[mid+1])continue;
                    if(j==0&&k==1)l=max(l,h[mid]+h[mid+1]);
                    if(j==1&&k==0)r=min(r,h[mid]+h[mid+1]);
                    if(l<r)
                    {
                        c.L[i][o]=min(c.L[i][o],l);
                        c.R[i][o]=max(c.R[i][o],r);
                    }
                }
        }
    return c;
}
void build(int k,int l,int r)
{
    if(l==r)
    {
        t[k].L[0][0]=t[k].L[1][1]=0;
        t[k].R[0][0]=t[k].R[1][1]=INF;
        return;
    }
    int mid=l+r>>1;
    build(k<<1,l,mid);
    build(k<<1|1,mid+1,r);
    t[k]=up(t[k<<1],t[k<<1|1],mid);
}
node ask(int k,int l,int r,int x,int y)
{
    if(x<=l&&r<=y)return t[k];
    int mid=l+r>>1;
    if(y<=mid)return ask(k<<1,l,mid,x,y);
    if(x>mid)return ask(k<<1|1,mid+1,r,x,y);
    return up(ask(k<<1,l,mid,x,y),ask(k<<1|1,mid+1,r,x,y),mid);
}
int check(node x)
{
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            if(x.L[i][j]<x.R[i][j])return 1;
    return 0;
}
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>h[i];
    build(1,1,n);
    int ans=0,r=1;
    for(int l=1;l<=n;l++)
    {
        r=max(r,l);
        while(r<=n&&check(ask(1,1,n,l,r)))r++;
        if(r>l)ans+=r-l-1;
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
