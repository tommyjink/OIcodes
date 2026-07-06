#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6;
int n,m,a[N],b[N],suma=0,sumb=0,ans=0;
bool cmp(int x,int y)
{
    return x>y;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=m;i++)
        cin>>b[i];
    sort(a+1,a+1+n,cmp);
    sort(b+1,b+1+m,cmp);
    for(int i=1;i<=n;i++)
    {
        suma+=a[i];
        if(b[i]>0)sumb+=b[i];
        ans=max(ans,suma+sumb);
    }
    cout<<ans<<endl;
    return 0;
}