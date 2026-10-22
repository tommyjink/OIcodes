#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=3e5+10;
int n,k,a[N],b[N],c[N],ans;
void dfs(int pos,int cnt,int sum)
{
    if(sum>=ans)return;
    if(pos>n)
    {
        for(int i=2;i<=n;i++)
            if(b[i]<b[i-1])return;
        ans=sum;
        return;
    }
    b[pos]=a[pos];
    dfs(pos+1,cnt,sum);
    if(cnt==k)return;
    for(int r=pos;r<=n;r++)
    {
        for(int i=pos;i<=r;i++)c[i]=a[i];
        sort(c+pos,c+r+1);
        for(int i=pos;i<=r;i++)b[i]=c[i];
        dfs(r+1,cnt+1,sum+r-pos+1);
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i];
    ans=n;
    dfs(1,0,0);
    cout<<ans<<endl;
    return 0;
}
