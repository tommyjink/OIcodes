#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int n,a[100][100],num=4;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    a[1][1]=1,a[1][2]=2,a[2][1]=3,a[2][2]=4;
    for(int i=3;i<=n;i++)
    {
        ++num;
        for(int j=1;j<=i-1;j++)
            a[i][j]=num;
        ++num;
        for(int j=1;j<=i-1;j++)
            a[j][i]=num;
        a[i][i]=4;
    }
    cout<<"Yes"<<endl;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}