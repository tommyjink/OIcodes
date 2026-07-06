#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int n,m,q;
int rk(int x)
{
    int res=0;
    for(int i=1;i<=n;i++)
        res+=min(x/i,m);
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m>>q;
    while(q--)
    {
        int k;
        cin>>k;
        int l=0,r=n*m;
        while(l<r)
        {
            int mid=(l+r)>>1;
            if(rk(mid)<k)
                l=mid+1;
            else r=mid;
            // printf("rk(%lld)=%lld\n",mid,rk(mid));
        }
        cout<<l<<endl;
    }
    return 0;
}