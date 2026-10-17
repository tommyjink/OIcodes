#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10,P=1e9+7;
int n,fa[N],ans=1,cnt[N],num[N];
int getfa(int x){return x==fa[x]?x:fa[x]=getfa(fa[x]);}
int gcd(int x,int y){return y?gcd(y,x%y):x;}
int lcm(int x,int y){return x/gcd(x,y)*y;}
int qpow(int x,int y)
{
    int res=1;
    while(y)
    {
        if(y&1)res=res*x%P;
        x=x*x%P;
        y>>=1;
    }
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)fa[i]=i;
    for(int i=1;i<=n;i++)
    {
        int x;cin>>x;
        int y=getfa(i);
        x=getfa(x);
        if(x==y)continue;
        else fa[x]=y;
    }
    for(int i=1;i<=n;i++)
        cnt[getfa(i)]++;
    for(int i=1;i<=n;i++)
    {
        if(!cnt[i])continue;
        // cout<<i<<":"<<cnt[i]<<endl;
        for(int j=2;j*j<=cnt[i];j++)
        {
            int tmp=0;
            while(cnt[i]%j==0)cnt[i]/=j,tmp++;
            num[j]=max(num[j],tmp);
            // if(tmp)cout<<i<<" "<<tmp<<endl;
        }
        if(cnt[i]>1)num[cnt[i]]=max(num[cnt[i]],1ll);
    }
    for(int i=1;i<N;i++)
        ans=(ans*qpow(i,num[i]))%P;
    cout<<ans<<endl;
    return 0;
}