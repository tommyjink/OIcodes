#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=2e6+10;
int n,a[N],b[N],c[N],d[N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("were.in","r",stdin);
    freopen("were.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)cin>>b[i];
    int cnt=1;
    memset(c,1,sizeof(c));
    for(int i=1;i<=n;i++)
    {
        int p=lower_bound(d+1,d+1+cnt,a[i])-d-1;
        if(p<=0||p>cnt){continue;}
        if(a[i]<c[p])c[p]=a[i],d[p+1]=a[i]*b[p];
        if(p==cnt)cnt++;
    }
    cout<<cnt-1<<endl;
    return 0;
}