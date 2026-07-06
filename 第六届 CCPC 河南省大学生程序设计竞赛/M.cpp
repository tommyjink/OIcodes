#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6;
int T,n,a[N],b[N];
bool check(int x)
{
    int l=0,r=1e10;
    for(int i=1;i<=n;i++)
    {
        int ll=a[i]-x*b[i];
        int rr=a[i]+x*b[i];
        if(i==1)l=ll,r=rr;
        else l=max(l,ll),r=min(r,rr);
        if(l>r)return false;
    }
    return true;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>T;
    while(T--)
    {
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        for(int i=1;i<=n;i++)
            cin>>b[i];
        int l=0,r=1e9;
        while(l<r)
        {
            int mid=(l+r)>>1;
            if(check(mid))r=mid;
            else l=mid+1;
        }
        cout<<l<<endl;
    }
    return 0;
}