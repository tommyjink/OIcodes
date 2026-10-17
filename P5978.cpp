#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,x,a[N],c[N],len=0,f[N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>x;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=n;i>=1;i--)
    {
        int l=1,r=len+1;
        while(l<r)
        {
            int mid=(l+r)>>1;
            if(c[mid]>a[i])l=mid+1;
            else r=mid;
        }
        f[i]=l;
        if(l==len+1)c[++len]=a[i];
        else c[l]=a[i];
    }
    len=0;
    int ans=len;
    for(int i=1;i<=n;i++)
    {
        int p=lower_bound(c+1,c+1+len,a[i]+x)-c-1;
        ans=max(ans,p+f[i]);
        p=lower_bound(c+1,c+1+len,a[i])-c;
        if(p==len+1)c[++len]=a[i];
        else c[p]=a[i];
    }
    cout<<ans<<endl;
    return 0;
}