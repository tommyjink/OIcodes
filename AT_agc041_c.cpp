#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1005;
int n;
string s[8];
char t[N][N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    s[4]=" orzzoreeeerozzro";
    s[5]=" orrzzoe..eae..ea.eezoorrz";
    s[6]=" oorrzz.e.e.e.e.e.ee.e.e.e.e.e.oorrzz";
    s[7]=" .oorrzzoaee...oa.a...reea...r...eaaz...e.ez...aae";
    cin>>n;
    if(n==2)cout<<-1,exit(0);
    if(n==3)cout<<"a..\na..\n.bb",exit(0);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            t[i][j]='.';
    int m=n%4+4,cnt=n/4-1;
    for(int i=1;i<=cnt;i++)
    {
        for(int j=1;j<=4;j++)
        {
            for(int k=1;k<=4;k++)
            {
                int x=(i-1)*4+j,y=(i-1)*4+k,z=(j-1)*4+k;
                t[x][y]=s[4][z];
            }
        }
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=m;j++)
        {
            int x=cnt*4+i,y=cnt*4+j,z=(i-1)*m+j;
            t[x][y]=s[m][z];
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            cout<<t[i][j];
        cout<<endl;
    }
    return 0;
}