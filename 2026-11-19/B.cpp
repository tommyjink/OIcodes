#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,k,d;
int prime[N],cnt=0,tag[N],p[N];
int fac[N],num=0,c[N],a[N],b[N];
void init()
{
    p[1]=1;
    for(int i=2;i<N;i++)
    {
        if(!tag[i])prime[++cnt]=i,p[i]=i-1;
        for(int j=1;j<=cnt;j++)
        {
            int x=prime[j]*i;
            if(x>=N)break;
            tag[x]=true;
            if(i%prime[j])p[x]=p[i]*(prime[j]-1);
            else
            {
                p[x]=p[i]*prime[j];
                break;
            }
        }
    }
}
int cal(int m,int d)
{
    int res=m;
    for(int i=1;i<(1<<num);i++)
    {
        int now=__builtin_popcount(i),k=1;
        for(int j=1;j<=num;j++)
            if((i>>(j-1))&1)
                k*=fac[j];
        if(now&1)res-=m/k;
        else res+=m/k;
    }
    return res;
}
void solve()
{
    cin>>n>>k;
    d=n+2;
    num=0;
    int dd=d;
    for(int i=1;prime[i]*prime[i]<=d;i++)
    {
        int now=0;
        while(dd%prime[i]==0)dd/=prime[i],now++;
        if(now)fac[++num]=prime[i],c[num]=now;
    }
    if(dd>1)fac[++num]=dd,c[num]=1;
    if(k==-1){cout<<cal(d,d)<<endl;return;}
    if(k>cal(d,d)){cout<<-1<<endl;return;}
    int l=1,r=d-1;
    while(l<r)
    {
        int mid=(l+r)>>1;
        if(cal(mid,d)<k)l=mid+1;
        else r=mid;
    }
    int x=l,y=d-l;
    int now=0;
    while(x!=1||y!=1)
    {
        if(x>y)
        {
            a[++now]=1;
            int mn=(x-1)/y;
            x-=mn*y;
            b[now]=mn;
        }
        else
        {
            a[++now]=0;
            int mn=(y-1)/x;
            y-=mn*x;
            b[now]=mn;
        }
    }
    cout<<now<<" "<<a[1]<<" ";
    for(int i=1;i<=now;i++)
        cout<<b[i]<<" ";
    cout<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    int t;cin>>t;
    while(t--)solve();
    return 0;
}