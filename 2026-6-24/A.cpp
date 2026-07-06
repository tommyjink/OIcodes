#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=1e6+10;
int n,a[N],f[N],pre[N],nxt[N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=nxt[0];j;j=nxt[j])
            f[i]=max(f[i],f[j]+(a[i]&a[j]));
        nxt[i-1]=i;
        pre[i]=i-1;
        for(int j=nxt[0];j&&j<i;j=nxt[j])
        {
            if(f[j]+a[j]<=f[i])
            {
                pre[nxt[j]]=pre[j];
                nxt[pre[j]]=nxt[j];
            }
        }
    }
    cout<<f[n]<<endl;
    return 0;
}
