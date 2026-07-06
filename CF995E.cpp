#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int M=21;
int u,v,p,done=false,ans=0;
map<int,vector<int>> mp;
map<int,int> cnt;
vector<int> step(M);
int qpow(int x,int y,int p)
{
    int res=1;
    while(y)
    {
        if(y&1)res=res*x%p;
        y>>=1;
        x=x*x%p;
    }
    return res;
}
void dfs(int x,int k,int mode)
{
    // cout<<x<<" "<<k<<endl;
    if(mode&&!mp.count(x))mp[x]=step,cnt[x]=k;
    else if(mp.count(x)&&!mode)done=k+1,ans=x;
    if(done)return;
    if(k==M) return;
    step[k]=1;
    if(k==0||step[k-1]!=2)dfs(x+1,k+1,mode);
    if(done)return;
    step[k]=2;
    if(k==0||step[k-1]!=1)dfs(x-1,k+1,mode);
    if(done)return;
    step[k]=3;
    if(k==0||step[k-1]!=3)dfs(qpow(x,p-2,p),k+1,mode);
    if(done)return;
}
int f(int x)
{
    if(x==1)return 2;
    if(x==2)return 1;
    return 3;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>u>>v>>p;
    dfs(u,0,1);
    step.clear();
    dfs(v,0,0);
    cout<<cnt[ans]+done-1<<endl;
    for(int i=0;i<cnt[ans];i++)
        cout<<mp[ans][i]<<" ";
    for(int i=done-2;i>=0;i--)
        cout<<f(step[i])<<" ";
    return 0;
}