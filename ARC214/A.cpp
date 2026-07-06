#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=105;
int n,a[N][N];
void rev()
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n/2;j++)
            swap(a[i][j],a[i][n-j+1]);
}
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
        {
            if(s[j-1]=='?')a[i][j]=-1;
            else a[i][j]=s[j-1]-'0';
        }
    }
    rev();
    // for(int i=1;i<=n;i++)
    // {
    //     for(int j=1;j<=n;j++)
    //         cout<<a[i][j]<<" ";
    //     cout<<endl;
    // }
    for(int i=1;i<=n;i++)
    {
        int now=-1;
        for(int j=1;j<=n-i+1;j++)
        {
            // cout<<a[i+j-1][j]<<endl;
            if(a[i+j-1][j]==-1)continue;
            if(a[i+j-1][j]!=-1&&now==-1)now=a[i+j-1][j];
            else if(now!=a[i+j-1][j])cout<<"-1",exit(0);
        }
        if(now==-1)now=0;
        for(int j=1;j<=n-i+1;j++)a[i+j-1][j]=now;
    }
    for(int i=2;i<=n;i++)
    {
        int now=-1;
        for(int j=1;j<=n-i+1;j++)
        {
            // cout<<a[j][i+j-1]<<endl;
            if(a[j][i+j-1]==-1)continue;
            if(a[j][i+j-1]!=-1&&now==-1)now=a[j][i+j-1];
            else if(now!=a[j][i+j-1])cout<<"-1",exit(0);
        }
        if(now==-1)now=0;
        for(int j=1;j<=n-i+1;j++)a[j][i+j-1]=now;
    }
    rev();
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            cout<<a[i][j];
        cout<<endl;
    }
    return 0;
}