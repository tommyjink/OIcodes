#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=105,M=1e6+10;
int n,a[N],vis[N],s,t,tt=0;
int prime[N],tot=0,head[N];
void init()
{
    for(int i=2;i<N;i++)
    {
        if(!vis[i])prime[++tot]=i;
        for(int j=1;j<=tot;j++)
        {
            int x=prime[j]*i;
            if(x>=N)break;
            vis[x]=true;
            if(i%prime[j]==0)break;
        }
    }
}
struct node
{
    int to,next;
}e[N*2];
void add(int x,int y)
{
    e[++tt]=(node){y,head[x]};
    head[x]=tt;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    s=2*n+1,t=s+1;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(i!=j&&!vis[a[i]+a[j]])

    return 0;
}