#include<bits/stdc++.h>
#define int long long
#define lowbit(x) x&(-x)
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,x,y,z,a[N],b[N],p[N];
int f[2][N],l=1,t[N*2];
void add(int x,int d)
{
    for(int i=x;i<=2*n;i+=lowbit(i))t[i]+=d;
}
int query(int x)
{
    int res=0;
    for(int i=x;i;i-=lowbit(i))res+=t[i];
    return res;
}
int sum(int l,int r)
{
    if(l>r)r+=n;
    if(r-l>=n)r-=n;
    return query(r)-query(l-1);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // n=10;
    // while(1)
    // {
    //     int op;
    //     cin>>op;
    //     if(op==1)
    //     {
    //         int x,y;
    //         cin>>x>>y;
    //         add(x,y);
    //     }
    //     else
    //     {
    //         int x;
    //         cin>>x;
    //         cout<<query(x)<<endl;
    //     }
    //     for(int i=1;i<=n;i++)
    //         cout<<query(i)-query(i-1)<<" ";
    //     cout<<endl;
    // }
    cin>>n>>x>>y>>z;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)cin>>b[i];
    for(int i=1;i<=n;i++)p[a[i]]=i;
    for(int i=1;i<=2*n;i++)add(i,1);
    memset(f,127,sizeof(f));
    f[1][0]=z;
    f[0][0]=0;
    for(int i=1;i<=n;i++)
    {
        int sum1=sum(l,p[b[i]])-sum(p[b[i]],p[b[i]]);
        int sum2=sum(p[b[i]]+1,l+n);
        f[0][i]=min(f[0][i],f[0][i-1] + sum1 * x);
        f[0][i]=min(f[0][i],f[0][i-1] + sum2 * y);
        f[0][i]=min(f[0][i],f[1][i-1] + sum1 * x + z);
        f[0][i]=min(f[0][i],f[1][i-1] + sum2 * y + z);

        f[1][i]=min(f[1][i],f[0][i-1] + sum1 * y + z);
        f[1][i]=min(f[1][i],f[0][i-1] + sum2 * x + z);
        f[1][i]=min(f[1][i],f[1][i-1] + sum1 * y);
        f[1][i]=min(f[1][i],f[1][i-1] + sum2 * x);
        add(p[b[i]], -1);
        add(p[b[i]] + n, -1);
        l = p[b[i]];
    }
    cout<<min(f[0][n],f[1][n]);
    return 0;
}