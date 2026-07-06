#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6;
int n,a[N],f[N],ans=0;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        int res=1;
        if(a[i]!=1)
            res=max(res,f[a[i]]+1);
        for(int j=2;j*j<=a[i];j++)
        {
            if(a[i]%j)continue;
            int k=a[i]/j;
            res=max(res,f[j]+1);
            res=max(res,f[k]+1);
        }
        for(int j=2;j*j<=a[i];j++)
        {
            if(a[i]%j)continue;
            int k=a[i]/j;
            f[j]=max(f[j],res);
            f[k]=max(f[k],res);
        }
        if(a[i]!=1)
            f[a[i]]=max(f[a[i]],res);
        ans=max(ans,res);
    }
    cout<<ans<<endl;

    return 0;
}