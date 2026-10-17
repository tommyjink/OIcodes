#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e5+10;
int n,a[N],b[N],p[N];
int len=0,c[N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i],p[a[i]]=i;
    for(int i=1;i<=n;i++)
        cin>>b[i],a[p[b[i]]]=i;
    // for(int i=1;i<=n;i++)
    //     cout<<a[i]<<" ";
    // cout<<endl;
    for(int i=1;i<=n;i++)
    {
        int p=lower_bound(c+1,c+1+len,a[i])-c;
        if(p==len+1)c[++len]=a[i];
        else c[p]=a[i];
    }
    cout<<len<<endl;
    return 0;
}