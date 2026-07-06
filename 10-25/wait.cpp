#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=100,P=1e9+3;
struct node
{
    int m[N][N];
};
node operator *(node x,node y)
{
    node res;
    memset(res.m,0,sizeof(res.m));
    for(int i=1;i<N;i++)
        for(int j=1;j<N;j++)
            for(int k=1;k<N;k++)
                res.m[i][j]=(res.m[i][j]+x.m[i][k]*y.m[k][j]%P)%P;
    return res;
}
node qpow(node x,int y)
{
    node res;
    memset(res.m,0,sizeof(res.m));
    for(int i=1;i<N;i++)
        res.m[i][i]=1;
    while(y)
    {
        if(y&1)res=res*x;
        y>>=1;
        x=x*x;
    }
    return res;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    node A,B,C;
    memset(A.m,0,sizeof(A.m));
    memset(B.m,0,sizeof(B.m));
    memset(C.m,0,sizeof(C.m));
    A.m[1][2]=A.m[2][1]=A.m[2][2]=1;
    B.m[2][1]=1;
    int n=0;
    cin>>n;
    C=qpow(A,n)*B;
    cout<<C.m[1][1];
    return 0;
}