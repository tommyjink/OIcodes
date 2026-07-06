#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=2e6+10;
const int limit=1<<20,p=20;
const int P=998244353,G=3;
const int Gi=332748118; 
int n,a[N],k,r[N];
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
void ntt(int *A,int type)
{
    for(int i=0;i<limit;i++)
        if(i<r[i])swap(A[i],A[r[i]]);
    for(int len=1;len<limit;len<<=1)
    {
        int Wn=qpow((type==1?G:Gi),(P-1)/(len<<1));
        for(int i=0;i<limit;i+=len<<1)
        {
            int w=1;
            for(int j=0;j<len;j++,w=Wn*w%P)
            {
                int x=A[i+j],y=A[i+j+len]*w%P;
                A[i+j]=(x+y)%P;
                A[i+j+len]=(x-y+P)%P;
            }
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(int i=0;i<limit;i++)
        r[i]=(r[i>>1ll]>>1ll)|((i&1ll)<<(p-1));
    cin>>n>>k;
    for(int i=1;i<=k;i++)
    {
        int x;cin>>x;
        a[x]=1;
    }
    ntt(a,1);
    for(int i=0;i<limit;i++)
        a[i]=qpow(a[i],n/2);
    ntt(a,-1);
    int inv=qpow(limit,P-2);
    for(int i=0;i<limit;i++)
        a[i]=a[i]*inv%P;
    int ans=0;
    for(int i=0;i<limit;i++)
        ans=(ans+a[i]*a[i]%P)%P;
    cout<<ans<<endl;
    return 0;
}