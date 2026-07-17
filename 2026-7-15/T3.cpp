#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=2005;
int n,a[N][N],b[N][N],q;
void sor(int *a)
{
    for(int i=1;i<=n-1;i++)
        if(a[i]>a[i+1])swap(a[i],a[i+1]);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[0][i];
    for(int i=1;i<=n-1;i++)
    {
        for(int j=1;j<=n;j++)
            a[i][j]=a[i-1][j];
        sor(a[i]);
        for(int j=1;j<=n;j++)
            b[i][a[i][j]]=j;
    }
    cin>>q;
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        cout<<b[x][y]<<endl;
    }
    return 0;
}