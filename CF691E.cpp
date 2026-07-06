#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=205,P=1e9+7;
int n,k,a[N];
struct node
{
    int m[N][N];
}B,A;
node operator *(node x,node y)
{
    node res;
    memset(res.m,0,sizeof(res.m));
    for(int i=1;i<=150;i++)
        for(int j=1;j<=150;j++)
            for(int k=1;k<=150;k++)
                res.m[i][j]=(res.m[i][j]+x.m[i][k]*y.m[k][j]%P)%P;
    return res;
}
node qpow(node x,int y)
{
    node res;
    memset(res.m,0,sizeof(res.m));
    for(int i=1;i<=150;i++)
        res.m[i][i]=1;
    while(y)
    {
        if(y&1)res=res*x;
        y>>=1,x=x*x;
    }
    return res;
}
void print(node x)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            cout<<x.m[i][j]<<" ";
        cout<<endl;
    }
    cout<<"________________"<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(A.m,0,sizeof(A.m));
    memset(B.m,0,sizeof(B.m));
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        B.m[i][1]=1;
        for(int j=1;j<=n;j++)
            A.m[i][j]=(__builtin_popcountll(a[i]^a[j])%3==0);
    }
    // print(A);
    // print(B);
    // print(A*B);
    // print(A*A*B);
    A=qpow(A,k-1)*B;
    int ans=0;
    for(int i=1;i<=n;i++)
        ans=(ans+A.m[i][1])%P;
    cout<<ans<<endl;
    return 0;
}