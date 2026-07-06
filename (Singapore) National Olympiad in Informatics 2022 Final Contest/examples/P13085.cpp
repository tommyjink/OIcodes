#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int f[20][10],a[20];
int dfs(int pos,int pre,int limit,int allzero)
{
    if(pos==0)return 1;
    if(!allzero&&!limit&&f[pos][pre])return f[pos][pre];
    int up=limit?min(a[pos],9ll):9,res=0;
    for(int i=0;i<=up;i++)
    {
        if(!allzero&&abs(i-pre)<2)continue;
        res+=dfs(pos-1,i,limit&&i==up,i==0&&allzero);
    }
    if(!allzero&&!limit)return f[pos][pre]=res;
    return res;
}
int solve(int n)
{
    int cnt=0;
    while(n)a[++cnt]=n%10,n/=10;
    memset(f,0,sizeof(f));
    return dfs(cnt,100,1,1);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int l,r;
    cin>>l>>r;
    cout<<solve(r)-solve(l-1)<<endl;
    return 0;
}