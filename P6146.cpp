#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
#define lowbit(x) (x&(-x))
using namespace std;
const int N=1e6+10,P=1e9+7;
int n,t[N],r[N];
void add(int x,int d)
{
    for(int i=x;i<=2*n;i+=lowbit(i))
        t[i]+=d;
}
int sum(int x)
{
    int res=0;
    for(int i=x;i;i-=lowbit(i))
        res+=t[i];
    return res;
}
int qpow(int x,int y)
{
    int res=1;
    while(y)
    {
        if(y&1)res=res*x%P;
        x=x*x%P;
        y>>=1;
    }
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x,y;cin>>x>>y;
        r[x]=y;
    }
    int ans=0,cnt=n;
    for(int i=1;i<=2*n;i++)
    {
        if(r[i])add(r[i],1),cnt--;
        else ans=(ans+qpow(2,sum(i-1)+cnt))%P;
    }
    cout<<ans<<endl;
    return 0;
}