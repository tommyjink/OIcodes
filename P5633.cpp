#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,m,s,k,fa[N],ans,m1=0,m2=0;
struct node{int x,y,z;}e1[N],e2[N],e[N];
bool cmp(node x,node y)
{
    if(x.z!=y.z)return x.z<y.z;
    if((x.x==s||x.y==s)&&(y.x==s||y.y==s))return x.x<y.x;
    return !(x.x==s||x.y==s);
}
int getfa(int x){return x==fa[x]?x:fa[x]=getfa(fa[x]);}
bool merge(int x,int y)
{
    x=getfa(x),y=getfa(y);
    if(x==y)return false;
    fa[x]=y;
    return true;
}
int check(int c)
{
    int cnt=0;ans=0;
    int p1=1,p2=1,now=0;
    while(p1<=m1&&p2<=m2)
    {
        if(cmp({e1[p1].x,e1[p1].y,e1[p1].z+c},e2[p2]))e[++now]={e1[p1].x,e1[p1].y,e1[p1].z+c},p1++;
        else e[++now]=e2[p2],p2++;
    }
    while(p1<=m1)e[++now]={e1[p1].x,e1[p1].y,e1[p1].z+c},p1++;
    while(p2<=m2)e[++now]=e2[p2],p2++;
    for(int i=1;i<=n;i++)fa[i]=i;
    for(int i=1;i<=m;i++)
    {
        if(merge(e[i].x,e[i].y))
        {
            if(e[i].x==s||e[i].y==s)cnt++;
            ans+=e[i].z;
        }
    }
    return cnt;
}
void WQS()
{
    int l=-30005,r=30005;
    if(k>check(l)||k<check(r))cout<<"Impossible"<<endl,exit(0);
    while(l<r)
    {
        int mid=l+(r-l)/2;
        if(check(mid)>k)l=mid+1;
        else r=mid;
    }
    check(l);
    cout<<ans-k*l<<endl,exit(0);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m>>s>>k;
    for(int i=1;i<=m;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        if(x==s||y==s)e1[++m1]={x,y,z};
        else e2[++m2]={x,y,z};
    }
    sort(e1+1,e1+1+m1,cmp);
    sort(e2+1,e2+1+m2,cmp);
    for(int i=1;i<=n;i++)fa[i]=i;
    WQS();
    return 0;
}