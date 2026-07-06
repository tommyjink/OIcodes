#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=2e6+10;
int n,m,s[N*2],k,x,y,z;
inline int f(int x,int y)
{
    return x*m+y+1;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        string t;
        cin>>t;
        for(int j=1;j<=m;j++)
            s[f(i,j)]=t[j-1]-'0'+s[f(i,j-1)];
    }
    cin>>k>>x>>y>>z;
    int a=1,b=n,ans=0;
    for(int i=1;i<=k;i++)
    {
        
    }
    return 0;
}