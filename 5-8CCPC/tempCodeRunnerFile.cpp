#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=100;
int n,m,mp[N][N],cnt=0,a[N][N],b[N][N],c[N][N],d[N][N],p=1;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    cnt=2*n+2*m-4;
    for(int i=1;i<=n;i++)
    {
        mp[i][1]=mp[i][m]=1;
        c[i][1]=1,d[i][m]=1;
    }
    for(int i=1;i<=m;i++)
    {
        mp[1][i]=mp[n][i]=1;
        a[1][i]=1,b[n][i]=1;
    }
    while(cnt<n*m)
    {
        p++;
        queue<pair<int,int>> q;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                if(i==p||i==n-p+1||j==p||j==m-p+1)
                    q.push(make_pair(i,j));
        while(!q.empty())
            {
                int i=q.front().first,j=q.front().second;
                q.pop();
                if(mp[i][j])continue;
                cnt++;
                if(mp[i][j+1]==2||mp[i][j+1]==3)
                    mp[i][j]=1,d[i][j]=1;
                if(mp[i][j-1]==2||mp[i][j-1]==3)
                    mp[i][j]=1,c[i][j]=1;
                if(mp[i-1][j]==2||mp[i-1][j]==3)
                    mp[i][j]=1,a[i][j]=1;
                if(mp[i+1][j]==2||mp[i+1][j]==3)
                    mp[i][j]=1,b[i][j]=1;
                if(mp[i][j])
                {
                    if(mp[i-1][j]==1)a[i][j]=2;
                    if(mp[i+1][j]==1)b[i][j]=2;
                    if(mp[i][j-1]==1)c[i][j]=2;
                    if(mp[i][j+1]==1)d[i][j]=2;
                    continue;
                }
                if((a[i-1][j]<=1||b[i+1][j]<=1)&&(c[i][j-1]<=1||d[i][j+1]<=1))
                {
                    mp[i][j]=3;
                    continue;
                }
                mp[i][j]=2;
                continue;
            }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(mp[i][j]==1)cout<<"1";
            else if(mp[i][j]==2)cout<<"+";
            else cout<<"*";
        }
        cout<<endl;
    }
    return 0;
}
/*
9 9
1 1 1 1 1 1 1 1 1 
1 * 1 * 1 * 1 * 1 
1 1 + 1 + 1 + 1 1 
1 * 1 * 1 * 1 * 1 
1 1 + 1 * 1 * 1 1 
1 * 1 * 1 * 1 * 1 
1 1 + 1 * 1 * 1 1 
1 * 1 * 1 * 1 * 1 
1 1 1 1 1 1 1 1 1
*/