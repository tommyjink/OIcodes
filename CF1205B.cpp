#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10,M=300;
int n,a[N],f[M][M],mp[M][M];
vector<int> b[70];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]==0)i--,n--;
    }
    for(int i=1;i<=n;i++)
        for(int j=1;(1ll<<(j-1))<=a[i];j++)
            if(a[i]&(1ll<<(j-1)))b[j].push_back(i);
    if(n<=200)
    {
        int ans=1e9;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                f[i][j]=1e9,mp[i][j]=1e9;
        for(int i=1;i<=69;i++)
            for(auto j:b[i])
                for(auto k:b[i])
                    if(j!=k)f[j][k]=1,mp[j][k]=1;
        for(int k=1;k<=n;k++)
        {
            for(int i=1;i<k;i++)
                for(int j=i+1;j<k;j++)
                    ans=min(ans,mp[i][k]+mp[k][j]+f[i][j]);
            for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++)
                    f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
        }
        cout<<(ans==1e9?-1:ans)<<endl;
    }
    else
    {
        int tag=false;
        for(int i=1;i<=69;i++)
            if(b[i].size()>=3)tag=true;
        if(tag)cout<<"3"<<endl;
        else cout<<"-1"<<endl;
    }
    return 0;
}