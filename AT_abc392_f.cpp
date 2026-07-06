#include<bits/stdc++.h>
#define int long long
#define lowbit(x) ((x)&(-x))
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,t[N],p[N],a[N];
void add(int x,int d)
{
    for(int i=x;i<=n;i+=lowbit(i))
        t[i]+=d;
}
int query(int x)
{
    int res=0;
    for(int i=x;i;i-=lowbit(i))
        res+=t[i];
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>p[i],add(i,1);
    for(int i=n;i>=1;i--)
    {
        int l=1,r=n;
        while(l<r)
        {
            int mid=(l+r)>>1;
            if(query(mid)<p[i])l=mid+1;
            else r=mid;
        }
        a[l]=i;
        add(l,-1);
    }
    for(int i=1;i<=n;i++)
        cout<<a[i]<<" ";
    return 0;
}