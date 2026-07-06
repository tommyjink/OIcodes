#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e3;
int n,m,a[N][N],b[N][N],ans=0;
int val(int x,int y,int xx,int yy)
{
    return b[xx][yy]-b[x-1][yy]-b[xx][y-1]+b[x-1][y-1];
}
signed main()
{
    freopen("test.in","r",stdin);
    freopen("test2.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        for(int j=1;j<=m;j++)
        {
            if(s[j-1]=='#')
                a[i][j]=1;
            b[i][j]=b[i-1][j]+b[i][j-1]-b[i-1][j-1]+a[i][j];
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            for(int k=i;k<=n;k++)
                for(int kk=j;kk<=m;kk++)
                    if(val(i,j,k,kk)<=1)
                        ans++;
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