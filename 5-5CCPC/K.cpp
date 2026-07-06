#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int n,a[100][100];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n-2;i++)
    {
        for(int j=1;j<=n;j++)
            if(!a[j][i])a[j][i]=i*2-1;
        for(int j=1;j<=n;j++)
            if(!a[i][j])a[i][j]=i*2;
    }
    int num=2*n-4;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(!a[i][j])a[i][j]=++num;
    cout<<"Yes"<<endl;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}