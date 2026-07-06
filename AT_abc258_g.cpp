#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int> 
using namespace std;
const int N=3000+10;
int n;
pii f[N*N];
bitset<N> a[N];
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
            a[i][j]=s[j-1]-'0';
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(a[i][j])
            {
                // cout<<i<<","<<j<<":"<<(a[i]&a[j]).count()<<endl;
                // for(int k=1;k<=n;k++)
                //     cout<<(a[i]&a[j])[k]<<" ";
                // cout<<endl;
                ans+=(a[i]&a[j]).count();
            }
        }
    }
    cout<<ans/3;
    return 0;
}