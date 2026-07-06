#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e3;
int n,m,a[N][N],b[N][N],ans=0;
signed main()
{
    // freopen("test.in","r",stdin);
    // freopen("test1.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        for(int j=1;j<=m;j++)
            if(s[j-1]=='#')
            {
                a[i][j]=1;
                for(int k=1;k<=i;k++)
                    if(!b[k][j])
                        b[k][j]=i;
            }
    }
    for(int i=1;i<=n+1;i++)
    {
        for(int j=1;j<=m+1;j++)
        {
            if(!b[i][j])
                b[i][j]=n+1;
            // cout<<b[i][j]<<" ";
        }
        // cout<<endl;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            // printf("%lld,%lld:\n",i,j);
            int t1=n+1,t2=b[min(b[i][j]+1,n+1)][j];
            // cout<<t2<<endl;
            for(int k=j;k<=m;k++)
            {
                if(b[i][k]<=t1)
                    t1=max(min(t2-1,b[min(n+1,b[i][k]+1)][k]-1),b[i][k]-1);
                // printf("%lld ",t1);
                ans+=t1-i+1;
                t2=min(t2,b[i][k]);
            }
            // cout<<endl;
        }
    }
    cout<<ans<<endl;
    return 0;
}

/*
3 3
...
...
..#
36

----------

2 2
..
##
7

---------

4 4
....
.#..
#...
#.#.
76

5 5
.....
#..#.
..#.#
.....
..#..

*/