#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=3e5+10,M=1100;
int n,a[N],phi[N],vis[N],pri[N],tot=0;
int fac[N],cnt[N],g[M],f[M];
void init()
{
    phi[1]=1;
    for(int i=2;i<N;i++)
    {
        if(!vis[i])pri[++tot]=i,phi[i]=i-1;
        for(int j=1;j<=tot;j++)
        {
            if(i*pri[j]>=N)break;
            vis[i*pri[j]]=true;
            fac[i*pri[j]]=pri[j];
            if(i%pri[j])phi[i*pri[j]]=phi[i]*(pri[j]-1);
            else {phi[i*pri[j]]=phi[i]*pri[j];break;}
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i],cnt[a[i]]++;
    for(int i=1;i<N;i++)
    {
        for(int j=2*i;j<N;j+=i)
        {
            cnt[i]+=cnt[j];
        }
    }
    int ans=1e9;
    for(int i=1;i<=n;i++)
    {
        if(a[i]==1)cout<<1<<endl,exit(0);
        int m=0,v[10]={0},t=a[i];
        while(vis[t])
        {
            v[++m]=fac[t];
            while(t%v[m]==0)t/=v[m];   
        }
        if(t>1)v[++m]=t;
        for(int s=0;s<(1<<m);s++)
        {
            int tmp=1;
            for(int j=1;j<=m;j++)
                if(s&(1<<(j-1)))
                    tmp*=v[j];
            g[s]=cnt[tmp];
        }
        for(int j=1;j<=m;j++) 
        {
            for(int s=0;s<(1<<m);s++)
            {
                if(s&(1<<(j-1)))continue;
                g[s]-=g[s|(1<<(j-1))];
            }
        }
        int full=(1<<m)-1;
        f[0]=0;
        for(int s=1;s<(1<<m);s++)
        {
            f[s]=n+1;
            for(int t=s;t;t=(t-1)&s)
                if(g[full^t])f[s]=min(f[s],f[s^t]+1);
            for(int t=s;t;t=(t-1)&s)
                f[s^t]=min(f[s^t],f[s]);
        }
        ans=min(ans,f[full]+1);
    }
    if(ans>n)cout<<-1<<endl;
    else cout<<ans<<endl;
    return 0;
}