#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6,P=1e9+7;
vector<int> v;
int n,k,f[N],ans=0;
int qpow(int x,int y)
{
    int res=1;
    while(y)
    {
        if(y&1)res=res*x%P;
        y>>=1;
        x=x*x%P;
    }
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>k;
    for(int i=1;i*i<=n;i++)
    {
        if(n%i)continue;
        v.push_back(i);
        if(i*i!=n)v.push_back(n/i);
    }
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++)
    {
        f[i]=qpow(k,(v[i]+1)/2);
        for(int j=0;j<i;j++)
            if(v[i]%v[j]==0)
                f[i]=((f[i]-f[j])%P+P)%P;
        if(v[i]%2)ans=(ans+f[i]*v[i]%P)%P;
        else ans=(ans+f[i]*v[i]/2%P)%P;
    }
    cout<<ans<<endl;
    return 0;
}