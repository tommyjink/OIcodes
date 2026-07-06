// #include<bits/stdc++.h>
// #define int long long
// #define endl "\n"
// using namespace std;
// const int N=2005;
// int n,m,k,a[N][N],b[N][N];
// int task()
// {
//     int sum=0;
//     for(int i=1;i<=n;i++)
//         for(int j=1;j<=m;j++)
//             sum+=a[i][j];
//     if(k==1&&!sum)return 1;
//     if(k==1&&sum==1)return 2;
//     if(n<=50&&m<=50)return 3;
//     if(n<=500&&m<=500)return 4;
//     if(k==1)return 5;
//     return 6;
// }
// void solve1()
// {
//     cout<<(1+n)*n*(1+m)*m/4<<endl;
// }
// void solve2()
// {
//     for(int i=1;i<=n;i++)
//     {
//         for(int j=1;j<=m;j++)
//         {
//             if(a[i][j])
//             {
//                 cout<<(1+n)*n*(1+m)*m/4-i*j*(n-i+1)*(m-j+1)<<endl;
//                 return ;
//             }
//         }
//     }
// }
// void solve3()
// {
//     for(int i=1;i<=n;i++)
//         for(int j=1;j<=m;j++)
//             b[i][j]+=b[i][j-1]+a[i][j];
//     for(int i=1;i<=n;i++)
//         for(int j=1;j<=m;j++)
//             b[i][j]+=b[i-1][j];
//     int ans=0;
//     for(int i=1;i<=n;i++)
//     {
//         for(int j=1;j<=m;j++)
//         {
//             for(int ii=1;ii<=i;ii++)
//             {
//                 for(int jj=1;jj<=j;jj++)
//                 {
//                     if((i-ii+1)*(j-jj+1)<k)continue;
//                     if(b[i][j]-b[ii-1][j]-b[i][jj-1]+b[ii-1][jj-1])continue;
//                     ans++;
//                     // cout<<i<<","<<j<<","<<ii<<","<<jj<<endl;
//                 }
//             }
//         }
//     }
//     cout<<ans<<endl;
// }
// signed main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cin>>n>>m>>k;
//     for(int i=1;i<=n;i++)
//         for(int j=1;j<=m;j++)
//             cin>>a[i][j];
//     int t=task();
//     if(t==1)solve1();
//     else if(t==2)solve2();
//     else solve3();
//     return 0;
// }


#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=2000+10;
int n,m,k,a[N][N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>a[i][j];
    for(int i=1;i<=n;i++)
    {
        
    }
    return 0;
}