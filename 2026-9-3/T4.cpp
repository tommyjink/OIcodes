#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=3e3+10;
int n,m,p[N][N],a[N],b[N],id[N];
bool cmp(int x,int y)
{
    return a[x]>a[y];
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>p[i][j],a[j]+=p[i][j];
    int now=0;
    for(int i=1;i<=m;i++)
        b[i]+=a[i]/1000,now+=a[i]/1000,a[i]%=1000,id[i]=i;
    sort(id+1,id+1+m,cmp);
    for(int i=1;i<=n-now;i++)
        b[id[i]]++;
    
    return 0;
}