#include<bits/stdc++.h>
#define int long long
#define lowbit(x) x&(-x)
#define endl "\n"
using namespace std;
const int N=1e6+10,P=998244353;
int n,a[N],f[N],t[N];
//f[i]=1+(1/(a[i]+1))*sum(j:range(i,j+a[i]))f[j]
//f[i]=1+(1/(a[i]+1))*(f[i]+sum(j:range(i+1,i+a[i]))f[j])
//f[i]=1+(1/(a[i]+1))*f[i]+(1/(a[i]+1))*sum(j:range(i+1,i+a[i]))f[j]
//(a[i]/(a[i]+1))*f[i]=1+(1/(a[i]+1))*sum(j:range(i+1,i+a[i]))f[j]
//f[i]=(a[i]+1/(a[i]))+(1/a[i])*sum(j:range(i+1,i+a[i]))f[j]
int qpow(int x,int y)
{
    int res=1;
    x%=P;
    while(y)
    {
        if(y&1)res=res*x%P;
        y>>=1;
        x=x*x%P;
    }
    return res;
}
void add(int x,int d)
{
    for(int i=x;i<=n;i+=lowbit(i))
        t[i]+=d;
}
int query(int x)
{
    int res=0;
    for(int i=x;i;i-=lowbit(i))
        res=(res+t[i])%P;
    return res;
}
int sum(int l,int r)
{
    return query(r)-query(l-1);
}
int F(int x)
{
    return qpow(x,P-2);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n-1;i++)
        cin>>a[i];
    for(int i=n-1;i>=1;i--)
    {
        f[i]=(((a[i]+1)*F(a[i]))%P+(F(a[i])*sum(i+1,i+a[i]))%P)%P;
        add(i,f[i]);
    }    
    cout<<f[1];
    return 0;
}