#include<bits/stdc++.h>
#define endl "\n"
#define lowbit(x) (x&(-x))
using namespace std;
const int N=8005;
int n,p[N],t[N];
void add(int x,int d)
{
    for(int i=x;i<=n;i+=lowbit(i))
        t[i]+=d;
}
int sum(int x)
{
    int res=0;
    for(int i=x;i;i-=lowbit(i))res+=t[i];
    return res;
}
void init()
{
    for(int i=1;i<=n;i++)t[i]=0;
}
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>p[i];
    int base=0,ans=0;
    init();
    for(int i=1;i<=n;i++)
    {
        base+=i-1-sum(p[i]);
        add(p[i],1);
    }
    for(int l=1;l<=n;l++)
    {
        init();
        int now=0;
        for(int r=l;r<=n;r++)
        {
            now+=r-l-sum(p[r]);
            add(p[r],1);
            ans=max(ans,base-now+((r-l+1)*(r-l)/2)-now);
        }
    }
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}