#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define lowbit(x) (x&(-x))
using namespace std;
const int N=5005,M=N*N+10,INF=1e16;
int n,m,w,k;
int a[N],b[N],f[N][N];
int c[M*2],cnt=0;
int t[M*2];
void upd(int x,int d)
{
    if(c[lower_bound(c+1,c+1+cnt,x)-c]!=x)cout<<"!!";
    x=lower_bound(c+1,c+1+cnt,x)-c;
    for(int i=x;i<=cnt;i+=lowbit(i))
        t[i]=min(t[i],d);
}
int query(int x)
{
    if(c[lower_bound(c+1,c+1+cnt,x)-c]!=x)cout<<"!!";
    int res=INF;
    x=lower_bound(c+1,c+1+cnt,x)-c;
    for(int i=x;i;i-=lowbit(i))
        res=min(res,t[i]);
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m>>w>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i],a[i]+=a[i-1];
    for(int i=1;i<=m;i++)
        cin>>b[i],b[i]+=b[i-1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            c[++cnt]=a[i]+b[j];
            c[++cnt]=a[i]+b[j]+w;
        }
    }
    sort(c+1,c+1+cnt);
    cnt=unique(c+1,c+1+cnt)-c-1;
    for(int i=0;i<=cnt;i++)
        t[i]=INF;
    f[n][m]=0;
    upd(a[n]+b[m],0);
    for(int i=n;i>=0;i--)
    {
        for(int j=m;j>=0;j--)
        {
            if(i==n&&j==m)continue;
            f[i][j]=INF;
            for(int x=i;x<=n;x++)
            {
                for(int y=j;y<=m;y++)
                {
                    if(a[x]+b[y]<=a[i]+b[j]+w)
                    {
                        f[i][j]=min(f[i][j],f[x][y]+1);
                    }
                }
            }
        }
    }
    cout<<f[0][0]*k<<endl;
    return 0;
}