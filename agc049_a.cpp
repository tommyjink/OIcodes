#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=105;
int n,f[N][N],cnt[N];
double ans=0.0;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        for(int j=1;j<=n;j++)
            if(s[j-1]=='1')f[i][j]=1;
        f[i][i]=1;
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                f[i][j]|=(f[i][k]&f[k][j]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(f[i][j])cnt[j]++;
    for(int i=1;i<=n;i++)
        ans+=1.0/(cnt[i]*1.0);
    printf("%.12lf",ans);
    return 0;
}