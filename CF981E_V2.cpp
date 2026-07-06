#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e4+10,P=1e9+7;
int n,q,f[N],tag[N];
vector<int> op[N];
void add(int x)
{
    for(int i=n;i>=x;i--)
        f[i]=(f[i]+f[i-x])%P;;
}
void del(int x)
{
    for(int i=x;i<=n;i++)
        f[i]=((f[i]-f[i-x])%P+P)%P;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>q;
    f[0]=1ll;
    for(int i=1;i<=q;i++)
    {
        int l,r,x;
        cin>>l>>r>>x;
        op[l].emplace_back(x);
        op[r+1].emplace_back(-x);
    }
    for(int i=1;i<=n;i++)
    {
        for(auto j:op[i])
        {
            if(j>0)add(j);
            else del(-j);
        }
        for(int j=1;j<=n;j++)
            if(f[j])tag[j]=true;
    }
    int ans=0;
    for(int i=1;i<=n;i++)
        if(tag[i])ans++;
    cout<<ans<<endl;
    for(int i=1;i<=n;i++)
        if(tag[i])cout<<i<<" ";
    return 0;
}