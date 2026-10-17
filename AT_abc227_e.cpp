#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=31;
int n,lim,f[N][N][N][N*N];
int a[N],b[N],c[N],aa[N],bb[N],cc[N];
int x=0,y=0,z=0;
string s;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>s>>lim;
    n=s.length();
    s=" "+s;
    lim=min(lim,n*(n-1)/2);
    for(int i=1;i<=n;i++)
    {
        if(s[i]=='K')a[++x]=i,aa[i]=1;
        if(s[i]=='E')b[++y]=i,bb[i]=1;
        if(s[i]=='Y')c[++z]=i,cc[i]=1;
        aa[i]+=aa[i-1];
        bb[i]+=bb[i-1];
        cc[i]+=cc[i-1];
    }
    f[0][0][0][0]=1;
    for(int i=0;i<=x;i++)
    {
        for(int j=0;j<=y;j++)
        {
            for(int k=0;k<=z;k++)
            {
                for(int t=0;t<=lim;t++)
                {
                    int xx,yy,zz;
                    if(i&&t>=(xx=a[i]-1-min(aa[a[i]-1],i-1)-min(bb[a[i]-1],j)-min(cc[a[i]-1],k)))f[i][j][k][t]+=f[i-1][j][k][t-xx];
                    if(j&&t>=(yy=b[j]-1-min(aa[b[j]-1],i)-min(bb[b[j]-1],j-1)-min(cc[b[j]-1],k)))f[i][j][k][t]+=f[i][j-1][k][t-yy];
                    if(k&&t>=(zz=c[k]-1-min(aa[c[k]-1],i)-min(bb[c[k]-1],j)-min(cc[c[k]-1],k-1)))f[i][j][k][t]+=f[i][j][k-1][t-zz];
                }
            }
        }  
    }
    int ans=0;
    for(int i=0;i<=lim;i++)ans+=f[x][y][z][i];
    cout<<ans<<endl;
    return 0;
}