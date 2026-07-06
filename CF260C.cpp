#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,x,a[N],mn=1e9;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>x;
    for(int i=1;i<=n;i++)
        cin>>a[i],mn=min(mn,a[i]);
    for(int i=1;i<=n;i++)
        a[i]-=mn;
    int now=0;
    for(int i=1;i<=n;i++)
    {
        int p=(x-i+1+n-1)%n+1;
        if(a[p]==0)
        {
            a[p]+=mn*n+now;
            break;
        }
        else a[p]--,now++;
    }
    for(int i=1;i<=n;i++)
        cout<<a[i]<<" ";
    return 0;
}