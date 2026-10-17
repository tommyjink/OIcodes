#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define lowbit(x) (x&(-x))
using namespace std;
const int N=1e6+10;
int n,d[N],sum[N];
int t[N];
void add(int x,int d)
{
    for(int i=x;i<=n+1;i+=lowbit(i))
        t[i]=max(t[i],d);
}
int query(int x)
{
    int res=0;
    for(int i=x;i>0;i-=lowbit(i))
        res=max(res,t[i]);
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>d[i];
    add(n+1,1e15);
    for(int i=n;i>=1;i--)
    {
        int l=i+1,r=n+1;
        while(l<r)
        {
            int mid=(l+r)>>1;
            if(d[i]+i<=query(mid))r=mid;
            else l=mid+1;
        }
        if(l==n+1)sum[i]=d[i]*d[i];
        else sum[i]=sum[l]+(d[i]+d[i]-l+i)*(l-i);
        // cout<<l<<endl;
        add(i,d[i]+i);
    }
    for(int i=1;i<=n;i++)
        cout<<sum[i]<<endl;
    return 0;
}