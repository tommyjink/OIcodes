#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=5e5+10;
int Nn,n,m,a[N],b[N],ans=0,now=1;
bool chk(int x)
{
    for(int i=1;i<=(x>>1);i++)
        if(b[i]!=b[x-i+1])return false;
    return true;
}
void dfs(int x)
{
    if(x>Nn)
    {
        ans=(ans+1)%m;
        return;
    }
    for(int i=0;i<=1;i++)
    {
        b[x]=i;
        int p=now;
        bool flag=true;
        while(now<=n&&a[now]==x)
        {
            if(!chk(x))
            {
                flag=false;
                break;
            }
            now++;
        }
        if(flag)dfs(x+1);
        now=p;
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>Nn>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    dfs(1);
    cout<<ans%m<<endl;
    return 0;
}
