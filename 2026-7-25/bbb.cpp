#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,m,a[N];
inline int f(int x,int y)
{
    return (x-1)*m+y;
}
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)a[f(i,j)]=0;
    if(n*m*(n+1)*(m+1)%8){cout<<"No"<<endl;return;}
    int li=0,now=n*m*(n+1)*(m+1)/8;
    for(int i=1;i<=n;i++)
    {
        int lj=0;
        for(int j=1;j<=m;j++)
        {
            if((i+j)&1)continue;
            int tmp=0;
            if(li==i)tmp=(j-lj)*(n-i+1)*(m-j+1)-1;
            else tmp=(j-lj)*(i-li)*(n-i+1)*(m-j+1)-1;
            if(now>=tmp)now-=tmp,li=i,lj=j,a[f(i,j)]=1;
        }
    }
    if(now==0)
    {
        cout<<"Yes"<<endl;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cout<<a[f(i,j)]<<" ";
            }
            cout<<endl;
        }
    }
    else cout<<"No!"<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}