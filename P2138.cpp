#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e3;
int ans=0,f[N][N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string a,b;
    cin>>a>>b;
    if(a.length()<b.length())
        swap(a,b);
    int ma=a.length(),mb=b.length();
    a=' '+a,b=' '+b;
    for(int i=1;i<=ma;i++)
        for(int j=1;j<=mb;j++)
            if(a[i]==b[j])
                f[i][j]=max(f[i-1][j-1]+1,max(f[i-1][j],f[i][j-1]));
            else f[i][j]=max(f[i-1][j],f[i][j-1]);
    int k=f[ma][mb];
    // for(int i=1;i<=ma;i++)
    //     for(int j=1;j<=mb;j++)
    //     {
    //         printf("f[%lld][%lld]=%lld\n",i,j,f[i][j]);
    //     }
    while(k*2<ma)
    {
        k+=mb;
        mb*=2;
        ans++;
    }
    cout<<ans+1;
    return 0;
}