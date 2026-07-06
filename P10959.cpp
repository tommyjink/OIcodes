#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int a[20],f[20][100][100][100];
int dfs(int pos,int sum,int now,int p,int limit)
{
    if(now>sum)return 0;
    if(pos==0&&now==sum&&p==0)return 1;
    else if(pos==0)return 0;
    if(pos*9+now<sum)return 0;
    if(!limit&&~f[pos][sum][now][p])return f[pos][sum][now][p];
    int up=limit?a[pos]:9,res=0;
    for(int i=0;i<=up;i++)
        res+=dfs(pos-1,sum,now+i,(p*10+i)%sum,limit&&i==a[pos]);
    if(!limit)return f[pos][sum][now][p]=res;
    return res;
}   
int cal(int n)
{
    if(n==0)return 0;
    int cnt=0,ans=0;
    while(n)a[++cnt]=n%10,n/=10;
    for(int i=1;i<=cnt*9;i++)ans+=dfs(cnt,i,0,0,1);
    return ans;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(f,-1,sizeof(f));
    int l,r;
    while(cin>>l>>r)cout<<cal(r)-cal(l-1)<<endl;
    return 0;
}