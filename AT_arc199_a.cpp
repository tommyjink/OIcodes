#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e3+10;
int n,a[N][N],R[N],C[N],X[N],Y[N];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        for(int j=1;j<=n;j++)
            a[i][j]=s[j-1]-'0';
    }
    for(int i=1;i<=n;i++)cin>>R[i];
    for(int i=1;i<=n;i++)cin>>C[i];
    for(int i=1;i<=n;i++)
    {
        
    }
}   
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}