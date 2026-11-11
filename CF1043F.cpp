#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=3e5+10,M=1100;
int n,a[N],f[M],phi[N],vis[N],pri[N],tot=0;
int cnt[N],v[N][10],fac[N];
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
    // for(int i=1;i<=100;i++)
    //     cout<<phi[i]<<" ";
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        while(vis[a[i]])
        {
            cnt[i]++;
            v[i][cnt[i]]=fac[a[i]];
            int d=fac[a[i]];
            while(a[i]%d==0)a[i]/=d;
        }
        if(a[i]>1)v[i][++cnt[i]]=a[i];
        for()
    }
    return 0;
}