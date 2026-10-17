#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=105,S=2e5+10,P=998244353;
int n,k,r[N],dp[N][S],s[N],c[N],m=0;
int base[N],lim;
vector<int> v;
int get(int x,int pos)
{
    return (x%base[pos+1])/base[pos];
}
void add(int &x,int y)
{
    x=(x+y)%P;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>k;
    for(int i=1;i<=k;i++)
    {
        cin>>r[i];
        v.push_back(r[i]-r[i-1]);
    }
    sort(v.begin(),v.end());
    for(int i:v)
    {
        if(i!=s[m])s[++m]=i;
        c[m]++;
    }
    base[0]=1;
    for(int i=1;i<=m;i++)base[i]=base[i-1]*(c[i]+1);
    dp[0][base[m]-1]=1;
    for(int i=1;i<=n;i++)
    {
        for(int now=0;now<base[m];now++)
        {
            int free=0;
            for(int j=1;j<=m;j++)
            {
                int x=get(now,j-1);
                free+=s[j]*x;
                if(x==c[j])continue;
                add(dp[i][now],dp[i-1][now+base[j-1]]*(x+1)%P*s[j]%P*i);
            }
            free=n-free-(i-1);
            if(free>0)add(dp[i][now],dp[i-1][now]*free%P);
        }
    }
    cout<<dp[n][0]<<endl;
    return 0;
}