#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e7+10,P=1e9+7;
int l,r,tag[N],k=0;
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
    cin>>l>>r;
    for(int i=l;i<=r;i++)
    {
        if(tag[i])continue;
        k++;
        for(int j=i*2;j<=r;j+=i)
            tag[j]=true;
    }
    int n=r-l+1,ans=1;
    for(int i=1;i<=n+1;i++)
        ans=(ans*i)%P;
    cout<<(ans*k%P)*qpow(k+1,P-2)%P;
    return 0;
}