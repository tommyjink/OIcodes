#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1010,M=3010;
int n,m,ans,l,r,fa[N*2],f[N*2],val[N*2],tag[N*2],b[M];

struct node
{
    int x,y,l,r;
}a[M];

bool cmp(node x,node y)
{
    return x.r>y.r;
}

int getfa(int x)
{
    if(fa[x]==x)return x;
    return fa[x]=getfa(fa[x]);
}

int calc(int lim,int id)
{
    int cnt=n;
    for(int i=1;i<=2*n;i++)fa[i]=i,f[i]=0;
    for(int i=1;i<=m;i++)
        if(a[i].l<=lim)
        {
            int x=getfa(a[i].x),y=getfa(a[i].y);
            if(x==y)continue;
            ++cnt;
            fa[x]=fa[y]=cnt;
            f[x]=f[y]=cnt;
            val[cnt]=a[i].r;
        }
    if(getfa(1)!=getfa(n))return 0;
    int x=1;
    while(x)tag[x]=id,x=f[x];
    x=n;
    while(tag[x]!=id)x=f[x];
    return val[x];
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>a[i].x>>a[i].y>>a[i].l>>a[i].r;
        b[i]=a[i].l;
    }
    sort(a+1,a+m+1,cmp);
    for(int i=1;i<=m;i++)
    {
        int rr=calc(b[i],i);
        if(rr>=b[i]&&(rr-b[i]+1>ans||(rr-b[i]+1==ans&&b[i]<l)))
        {
            ans=rr-b[i]+1;
            l=b[i];
            r=rr;
        }
    }
    cout<<ans<<endl;
    if(ans)
    {
        for(int i=l;i<=r;i++)cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}
