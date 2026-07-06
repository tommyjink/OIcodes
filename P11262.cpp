#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define S(x) (x*x)
using namespace std;
const int N=1e6+10,P=1e6+3;
int n,m,a[N],sum[N],xo[N],sums[N],seed=P;
map<int,int> mp,ex;
int rnd()
{
    while(ex.count(seed))seed=(seed+998244353)%P*23%P;
    ex[seed]=true;
    return seed;
}
int rd(int x)
{
    if(mp.count(x))return mp[x];
    return mp[x]=rnd();
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        a[i]=rd(a[i]);
        sum[i]=sum[i-1]+a[i];
        sums[i]=sums[i-1]+S(a[i]);
        xo[i]=xo[i-1]^a[i];
    }
    // for(int i=1;i<=n;i++)cout<<a[i]<<" ";
    while(m--)
    {
        int l1,r1,l2,r2;
        cin>>l1>>r1>>l2>>r2;
        int x=(sums[r2]-sums[l2-1])-(sums[r1]-sums[l1-1]);
        int y=(sum[r2]-sum[l2-1])-(sum[r1]-sum[l1-1]);//a-b
        if(y==0||x%y)
        {
            cout<<"NE"<<endl;
            continue;
        }
        // cout<<x<<" "<<y<<endl;
        int z=x/y;//a+b
        int A=(y+z)/2,B=(z-A);
        // cout<<A<<" "<<B<<endl;
        if(ex.count(A)&&ex.count(B)&&(xo[r2]^xo[l2-1]^A)==(xo[r1]^xo[l1-1]^B))
            cout<<"DA"<<endl;
        else cout<<"NE"<<endl;
    }
    return 0;
}