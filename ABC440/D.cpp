#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,q,a[N];
map<int,int> mp;
int find(int x)
{
    return upper_bound(a+1,a+1+n,x)-a-1;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
        cin>>a[i],mp[a[i]]=true;
    sort(a+1,a+1+n);
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        int base=lower_bound(a+1,a+1+n,x)-a-1;
        int l=x,r=x+y+n;
        while(l<r)
        {
            int mid=(l+r)>>1;
            int p=find(mid);
            // cout<<l<<","<<mid<<","<<r<<":"<<p<<endl;
            int now=mid-x+1-(p-base);
            if(now<y)l=mid+1;
            else r=mid;
        }
        cout<<l<<endl;
    }
    return 0;
}