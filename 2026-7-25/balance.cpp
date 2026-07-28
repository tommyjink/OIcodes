#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int T,n,m,cnt;
int a[N],b[N];

int C(int x)
{
    return x*(x-1)/2;
}

void build(int n)
{
    int now=n*(n-3)/4,rem=n;
    cnt=0;
    while(now)
    {
        int l=2,r=rem,res=2;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(C(mid)<=now)res=mid,l=mid+1;
            else r=mid-1;
        }
        a[++cnt]=res;
        now-=C(res);
        rem-=res;
    }
    while(rem--)a[++cnt]=1;
    int c=0,nowp=0;
    for(int i=1;i<=cnt;i++)
    {
        // cout<<a[i]<<"!"<<endl;
        for(int j=1;j<=a[i];j++)
            b[++nowp]=c;
        c^=1;
    }
}

int calc(int x)
{
    return x*(x+1)/2%2;
}

void solve()
{
    cin>>n>>m;
    if(calc(n)&&calc(m))
    {
        cout<<"No"<<endl;
        return;
    }
    cout<<"Yes"<<endl;
    if(m*(m+1)/2%2==0)
    {
        build(m);
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
                cout<<b[j]<<" ";
            cout<<endl;
        }
    }
    else
    {
        build(n);
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
                cout<<b[i]<<" ";
            cout<<endl;
        }
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("balance.in","r",stdin);
    freopen("balance.out","w",stdout);
    cin>>T;
    while(T--)solve();
    return 0;
}
