#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e4+10,K=5e2+10,M=6e3+10;
int n,k,mx,ans;
int h[N],tr[M][K];
int lowbit(int x)
{
    return x&-x;
}
void add(int x,int val,int y)
{
    for(;x<=mx+k;x+=lowbit(x))
        for(int i=y;i<=k+1;i+=lowbit(i))
            tr[x][i]=max(tr[x][i],val);
}
int query(int x,int y)
{
    int res=0;
    for(;x;x-=lowbit(x))
        for(int i=y;i;i-=lowbit(i))
            res=max(res,tr[x][i]);
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>h[i];
        mx=max(mx,h[i]);
    }
    for(int i=1;i<=n;i++)
        for(int j=k;j>=0;j--)
        {
            int x=query(h[i]+j,j+1)+1;
            ans=max(ans,x);
            add(h[i]+j,x,j+1);
        }
    cout<<ans<<endl;
    return 0;
}
