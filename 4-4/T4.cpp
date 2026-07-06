#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int mod=998244353;
int T,n,m,a[30],nxt[30],s[30],cnt[30];
int qpow(int a,int b)
{
    int res=1;
    while(b)
    {
        if(b&1)res=res*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return res;
}
int calc(int k)
{
    int res=1;
    for(int i=0;i<k;i++)res=res*(m-i)%mod;
    return res;
}
void dfs(int x,int mx)
{
    if(x==n+1)
    {
        cnt[mx]++;
        return;
    }
    for(int i=1;i<=min(mx+1,m);i++)
    {
        s[x]=i;
        int j=nxt[x-1];
        while(j&&s[j+1]!=s[x])j=nxt[j];
        if(s[j+1]==s[x])j++;
        if(j!=a[x])continue;
        nxt[x]=j;
        dfs(x+1,max(mx,i));
    }
}
signed main()
{
    cin>>T;
    while(T--)
    {
        cin>>n>>m;
        for(int i=1;i<=n;i++)cin>>a[i];
        if(m==1)
        {
            int fl=1;
            for(int i=1;i<=n;i++)
                fl&=(a[i]==i-1);
            cout<<fl<<endl;
            continue;
        }
        if(n<=20)
        {
            for(int i=0;i<=n;i++)cnt[i]=0,nxt[i]=0,s[i]=0;
            if(a[1])
            {
                cout<<0<<endl;
                continue;
            }
            s[1]=1;
            nxt[1]=0;
            dfs(2,1);
            int ans=0;
            for(int i=1;i<=n;i++)ans=(ans+cnt[i]*calc(i))%mod;
            cout<<ans<<endl;
            continue;
        }
        cout<<0<<endl;
    }
    return 0;
}
