#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=55,M=405,K=820005;
int n,m,tot,tim;
int a[N][M],top[N],vis[N];
int ans[K][2];

void move(int x,int y)
{
    ans[++tot][0]=x;
    ans[tot][1]=y;
    a[y][++top[y]]=a[x][top[x]--];
}

void solve(int l,int r)
{
    if(l==r)return;
    int mid=(l+r)>>1,id=++tim;
    for(int i=l;i<=mid;i++)
        for(int j=mid+1;j<=r;j++)
        {
            // cout<<i<<" "<<j<<endl;
            if(vis[i]==id||vis[j]==id)continue;
            int cnt=0;
            for(int k=1;k<=m;k++)
                cnt+=(a[i][k]<=mid)+(a[j][k]<=mid);
            if(cnt>=m)
            {
                cnt=0;
                for(int k=1;k<=m;k++)cnt+=(a[i][k]<=mid);
                for(int k=1;k<=cnt;k++)move(j,n+1);
                while(top[i])
                {
                    if(a[i][top[i]]<=mid)move(i,j);
                    else move(i,n+1);
                }
                for(int k=1;k<=cnt;k++)move(j,i);
                for(int k=1;k<=m-cnt;k++)move(n+1,i);
                for(int k=1;k<=m-cnt;k++)move(j,n+1);
                for(int k=1;k<=m-cnt;k++)move(i,j);
                while(top[n+1])
                {
                    if(top[i]!=m&&a[n+1][top[n+1]]<=mid)move(n+1,i);
                    else move(n+1,j);
                }
                vis[i]=id;
            }
            else
            {
                cnt=0;
                for(int k=1;k<=m;k++)cnt+=(a[j][k]>mid);
                for(int k=1;k<=cnt;k++)move(i,n+1);
                while(top[j])
                {
                    if(a[j][top[j]]>mid)move(j,i);
                    else move(j,n+1);
                }
                for(int k=1;k<=cnt;k++)move(i,j);
                for(int k=1;k<=m-cnt;k++)move(n+1,j);
                for(int k=1;k<=m-cnt;k++)move(i,n+1);
                for(int k=1;k<=m-cnt;k++)move(j,i);
                while(top[n+1])
                {
                    if(top[j]!=m&&a[n+1][top[n+1]]>mid)move(n+1,j);
                    else move(n+1,i);
                }
                vis[j]=id;
            }
        }
    solve(l,mid);
    solve(mid+1,r);
}
// void print()
// {
//     for(int i=1;i<=n;i++)
//     {
//         for(int j=1;j<=m;j++)
//         {
//             if(a[i][j])cout<<a[i][j]<<" ";
//             else cout<<"! ";
//         }
//         cout<<endl;
//     }
// }
signed main()
{
    freopen("containers.in","r",stdin);
    freopen("containers.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)cin>>a[i][++top[i]];
    solve(1,n);
    cout<<tot<<endl;
    for(int i=1;i<=tot;i++)cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
    return 0;
}
