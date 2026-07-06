#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=3e3;
int n,m,ans=0;
bitset<N> a[N];
void gauss()
{
    for(int j=1;j<=n;j++)
    {
        for(int i=j;i<=m;i++)
        {
            if(a[i][j])
            {
                swap(a[i],a[j]);
                ans=max(ans,i);
                break;
            }
        }
        if(!a[j][j])
        {
            cout<<"Cannot Determine"<<endl;
            return ;
        }
        for(int i=1;i<=m;i++)
        {
            if(i==j||(!a[i][j]))continue;
            a[i]^=a[j];
        }
    }
    cout<<ans<<endl;
    for(int i=1;i<=n;i++)
    {
        if(a[i][n+1])
            cout<<"?y7M#"<<endl;
        else cout<<"Earth"<<endl;
        // for(int j=1;j<=n+1;j++)
        // {
        //     cout<<a[i][j]<<" ";
        // }
        // cout<<endl;
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        string s;
        cin>>s;
        for(int j=1;j<=n;j++)
            a[i][j]=s[j-1]-'0';
        int x;
        cin>>x;
        a[i][n+1]=x;
    }
    gauss();
    return 0;
}