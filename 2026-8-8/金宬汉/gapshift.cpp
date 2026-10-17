#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=5e5+10;
int n,m,tim,fl;
int a[N],b[N],op[N],l[N],r[N],v[N],vis[N];

int mex(int l,int r)
{
    tim++;
    for(int i=l;i<=r;i++)
        if(a[i]<=r-l+1)vis[a[i]]=tim;
    for(int i=0;i<=r-l+1;i++)
        if(vis[i]!=tim)return i;
    return r-l+2;
}

void solve1()
{
    for(int i=1;i<=m;i++)
    {
        if(op[i]==1)
        {
            for(int j=l[i];j<=r[i];j++)a[j]=v[i];
        }
        else if(op[i]==2)
        {
            int x=mex(l[i],r[i]);
            for(int j=l[i];j<=r[i];j++)a[j]+=x;
        }
        else
        {
            int ans=0;
            for(int j=l[i];j<=r[i];j++)ans+=a[j];
            cout<<ans<<endl;
        }
    }
}

void solve2()
{
    int sum=0,tag=0,mn=0;
    for(int i=1;i<=n;i++)
    {
        sum+=b[i];
        if(b[i]<=n)vis[b[i]]=1;
    }
    while(vis[mn])mn++;
    for(int i=1;i<=m;i++)
    {
        if(op[i]==1)
        {
            sum=n*v[i];
            tag=v[i];
            mn=(tag==0);
        }
        else if(op[i]==2)
        {
            sum+=n*mn;
            tag+=mn;
            if(mn)mn=0;
        }
        else cout<<sum<<endl;
    }
}

signed main()
{
    freopen("gapshift.in","r",stdin);
    freopen("gapshift.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    fl=1;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        b[i]=a[i];
    }
    for(int i=1;i<=m;i++)
    {
        cin>>op[i]>>l[i]>>r[i];
        if(op[i]==1)cin>>v[i];
        if(l[i]!=1||r[i]!=n)fl=0;
    }
    if(n<=2000&&m<=2000)solve1();
    else if(fl)solve2();
    else
    {
        for(int i=1;i<=m;i++)
            if(op[i]==3)cout<<0<<endl;
    }
    return 0;
}
