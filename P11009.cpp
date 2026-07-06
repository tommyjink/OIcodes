#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=100;
int ans[N+100];
void dfs(int x,int cnt)
{
    if(x>N)return;
    ans[x]=min(ans[x],cnt);
    dfs(x+(1ll<<x),cnt+1);
    dfs(x+log2(x-1),cnt+1);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    dfs(2,0);
    dfs(3,0);
    for(int i=1;i<=N;i++)
        cout<<i<<" "<<ans[i]<<endl;
    return 0;
}