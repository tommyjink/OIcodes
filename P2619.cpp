#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e5+10;
int n,m,k,fa[N],val=0;
struct node{int x,y,z,col;}e[N];
bool cmp(node x,node y){return x.z==y.z?x.col>y.col:x.z<y.z;}
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
    for(int i=1;i<=m;i++)if(!e[i].col)e[i].z+=c;
    for(int i=1;i<=n;i++)fa[i]=i;
    sort(e+1,e+1+m,cmp);
    int cnt=0;val=0;
    for(int i=1;i<=m;i++)
    {
        if(merge(e[i].x,e[i].y))
        {
            cnt+=1-e[i].col;
            val+=e[i].z;
        }
    }
    for(int i=1;i<=m;i++)if(!e[i].col)e[i].z-=c;
    return cnt;
}
void WQS()
{
    int l=-1e6,r=1e6;
    while(l<r)
    {
        int mid=l+(r-l)/2;
        if(check(mid)>k)l=mid+1;
        else r=mid;
    }
    check(l);
    cout<<val-k*l<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
        cin>>e[i].x>>e[i].y>>e[i].z>>e[i].col,
        e[i].x++,e[i].y++;
    WQS();
    return 0;
}