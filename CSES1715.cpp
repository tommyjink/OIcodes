#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10,P=1e9+7;
string s;
int cnt[30],fac[N],inv[N];
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
    fac[0]=1;
    for(int i=1;i<N;i++)fac[i]=fac[i-1]*i%P;
    inv[N-1]=qpow(fac[N-1],P-2);
    for(int i=N-2;i;i--)inv[i]=inv[i+1]*(i+1)%P;
    inv[0]=1;
    cin>>s;
    for(char c:s)cnt[c-'a']++;
    int ans=fac[s.length()];
    // cout<<ans<<" ";
    for(int i=0;i<='z'-'a';i++)
        ans=ans*inv[cnt[i]]%P;
    cout<<ans<<endl;
    return 0;
}