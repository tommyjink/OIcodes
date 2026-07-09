#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

const int N=4e7+10,M=1e7+10;

int n,tot,mid,r,ans,ps,pr;
int f[N],sum[N];
unsigned char b[N],xr[N];
char s[M],t[N];

inline void add(char c,int v,int z)
{
    t[++tot]=c;
    b[tot]=z;
    sum[tot]=sum[tot-1]+v;
    xr[tot]=xr[tot-1]^z;
}

inline void upd(int i)
{
    int l=i-f[i]+1,rr=i+f[i]-1;

    if((xr[rr]^xr[l-1])==0)
    {
        int tmp=sum[rr]-sum[l-1];
        if(tmp>ans)
        {
            ans=tmp;
            ps=i;
            pr=f[i];
        }
    }
}

void solve()
{
    cin>>n;
    scanf("%s",s+1);
    tot=mid=r=0;
    sum[0]=xr[0]=0;
    ans=-1;
    ps=pr=1;
    for(int i=1;i<=n;i++)
    {
        if(s[i]=='w')
        {
            add('v',1,1);
            add('#',0,0);
            add('v',1,1);
            add('#',0,0);
        }
        else
        {
            add(s[i],2,0);
            add('#',0,0);
        }
    }
    for(int i=1;i<=tot;i++)
    {
        if(i<=r)f[i]=min(f[mid*2-i],r-i+1);
        else f[i]=1;
        upd(i);
        while(i-f[i]>=1&&i+f[i]<=tot&&t[i-f[i]]==t[i+f[i]])
        {
            f[i]++;
            upd(i);
        }
        if(i+f[i]-1>r)
        {
            mid=i;
            r=i+f[i]-1;
        }
    }
    for(int i=ps-pr+1;i<=ps+pr-1;i++)
    {
        if(t[i]=='#')continue;
        if(b[i])
        {
            cout<<'w';
            i+=2;
        }
        else cout<<t[i];
    }
    cout<<endl;
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);

    int T;
    cin>>T;

    while(T--)solve();

    return 0;
}