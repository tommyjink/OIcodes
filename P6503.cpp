#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,a[N],pmin[N],pmax[N],nmin[N],nmax[N],ans=0;
stack<int> smin,smax;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
        nmin[i]=nmax[i]=n+1;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        while(!smin.empty()&&a[smin.top()]>=a[i])smin.pop();
        while(!smax.empty()&&a[smax.top()]<=a[i])smax.pop();
        if(!smin.empty())pmin[i]=smin.top();
        if(!smax.empty())pmax[i]=smax.top();
        smin.push(i),smax.push(i);
    }
    while(!smin.empty())smin.pop();
    while(!smax.empty())smax.pop();
    for(int i=n;i>=1;i--)
    {
        while(!smin.empty()&&a[smin.top()]>a[i])smin.pop();
        while(!smax.empty()&&a[smax.top()]<a[i])smax.pop();
        if(!smin.empty())nmin[i]=smin.top();
        if(!smax.empty())nmax[i]=smax.top();
        smin.push(i),smax.push(i);
    }
    // for(int i=1;i<=n;i++)
    //     cout<<pmin[i]<<","<<pmax[i]<<","<<nmin[i]<<","<<nmax[i]<<endl;
    for(int i=1;i<=n;i++)
    {
        ans+=(i-pmax[i])*(nmax[i]-i)*a[i];
        ans-=(i-pmin[i])*(nmin[i]-i)*a[i];
    }   
    cout<<ans<<endl;
    return 0;
}