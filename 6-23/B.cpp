#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,a[N],b[N],c[N],ans[N],d[N];
void solve1()
{
    for(int i=1;i<=n;i++)
        ans[i]=0;
    for(int i=1;i<=n;i++)
    {
        b[i]=c[i]=a[i];
        d[i]=d[i-1]+a[i];
        ans[1]+=abs(a[i]);
    }
    for(int i=2;i<=n;i++)
    {
        for(int j=n;j>=i;j--)
        {
            b[j]=max({b[j],b[j-1],d[j]-d[j-i]});
            c[j]=min({c[j],c[j-1],d[j]-d[j-i]});
            ans[i]=ans[i]+max(abs(b[j]),abs(c[j]));
        }
    }
    int res=0;
    for(int i=1;i<=n;i++)
        res^=(ans[i])%(i*i);
    cout<<res<<endl;
}
//1 1 1 1 1 1 1
//1 2 2 2 2 2 1
//1 2 3 3 3 2 1
//1 2 3 4 3 2 1
//1 2 3 3 3 2 1
//1 2 2 2 2 2 1
//1 1 1 1 1 1 1

//1 1 1 1
//1 2 2 1
//1 2 2 1
//1 1 1 1

//1 1 1 1 1 1
//1 2 2 2 2 1
//1 2 3 3 2 1
//1 2 3 3 2 1
//1 2 2 2 2 1
//1 1 1 1 1 1
void solve2()
{
    for(int i=1;i<=n;i++)
        ans[i]=0;
    for(int i=1;i<=n;i++)
    {
        b[i]=c[i]=a[i];
        d[i]=d[i-1]+a[i];
        ans[1]+=abs(a[i]);
    }
    int now=0;
    for(int i=1;i<=(n+1)/2;i++)
    {
        now+=d[n-i+1]-d[i-1];
        ans[i]=now;
        ans[n-i+1]=now;
    }
    int res=0;
    for(int i=1;i<=n;i++)
        res^=(ans[i])%(i*i);
    cout<<res<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        if(n<=5000)solve1();
        else solve2();
    }
    return 0;
}