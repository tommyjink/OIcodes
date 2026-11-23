#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
const int N=5e4+10;
int n[N],m[N],ans[N],mx=0,num[N],tot=0;
int prime[N],cnt=0,vis[N],fac[N];
vector<int> q[N];
bitset<N> f,s[N],pre; 
void init()
{
    for(int i=2;i<N;i++)
    {
        if(!vis[i])prime[++cnt]=i;
        for(int j=1;j<=cnt;j++)
        {
            if(prime[j]*i>=N)break;
            vis[prime[j]*i]=true;
            fac[prime[j]*i]=prime[j];
            if(i%prime[j]==0)break;
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    int t;cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>n[i]>>m[i];
        q[m[i]].push_back(i);
        mx=max(mx,m[i]);
    }
    for(int i=1;i<=mx;i++)
    {
        f=0;
        vector<int> h;
        int x=i;
        while(fac[x])
        {
            int d=fac[x];
            while(x%d==0)x/=d;
            h.push_back(d);
        }
        if(x>1)h.push_back(x);
        for(int j=0;j<(1<<(int)h.size());j++)
        {
            int res=1;
            for(int k=0;k<(int)h.size();k++)
                if((j>>k)&1)res=res*h[k];
            if(!num[res])num[res]=++tot;
            f^=s[num[res]];
        }
        f=(f<<1);
        f[1]=f[1]^1;
        for(int j=0;j<(1<<(int)h.size());j++)
        {
            int res=1;
            for(int k=0;k<(int)h.size();k++)
                if((j>>k)&1)res=res*h[k];
            if(!num[res])num[res]=++tot;
            s[num[res]]^=f;
        }
        pre=pre^f;
        for(int j:q[i])ans[j]=pre[n[j]];
    }
    for(int i=1;i<=t;i++)
        cout<<ans[i]<<endl;
    return 0;
}