#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=105,mod=1000000007;

struct node
{
    int l,r,v;
}a[N];

int n,m,tot,b[N],pw[N],s[3][N][N];
int f[N][N][N],g[N][N][N];

void solve()
{
    cin>>n>>m;
    int x=0,y=0;
    tot=0;
    b[++tot]=1;
    b[++tot]=n;
    for(int i=1;i<=m;i++)
    {
        cin>>a[i].l>>a[i].r>>a[i].v;
        b[++tot]=a[i].r;
        if(a[i].v==1) x++;
        else y++;
    }
    if(n==1)
    {
        cout<<((pw[x]-1)*pw[y]+2*(pw[y]-1))%mod<<endl;
        return;
    }

    sort(b+1,b+tot+1);
    tot=unique(b+1,b+tot+1)-b-1;
    memset(s,0,sizeof s);
    memset(f,0,sizeof f);
    memset(g,0,sizeof g);
    for(int i=1;i<=m;i++)
    {
        x=lower_bound(b+1,b+tot+1,a[i].l)-b;
        y=lower_bound(b+1,b+tot+1,a[i].r)-b;
        s[a[i].v][x][y]++;
    }
    for(int v=1;v<=2;v++)
        for(int i=1;i<=tot;i++)
            for(int j=1;j<=tot;j++)
                s[v][i][j]+=s[v][i-1][j]+s[v][i][j-1]
                            -s[v][i-1][j-1];

    f[0][0][1]=1;
    int ans=0;
    for(int i=0;i<=tot;i++)
        for(int j=i;j<=tot;j++)
            for(int k=j;k<=tot;k++)
            {
                if(!f[i][j][k]&&!g[i][j][k]) continue;
                if(k==tot)
                {
                    int cnt=m-s[1][j][tot]-s[2][i][tot];
                    ans=(ans+g[i][j][k]*pw[cnt])%mod;
                    continue;
                }
                if(i==k) continue;

                int pre=0,sum=(f[i][j][k]+g[i][j][k])%mod;
                for(int l=k;l<=tot;l++)
                {
                    int cnt=s[1][k][l]-s[1][j][l]
                           +s[2][j][l]-s[2][i][l];
                    int now=pw[cnt],w=(now-pre+mod)%mod;
                    pre=now;
                    if(!w) continue;
                    f[j][k][l]=(f[j][k][l]+f[i][j][k]*w)%mod;
                    g[j][k][l]=(g[j][k][l]+sum*w)%mod;
                }
            }
    cout<<ans<<endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    pw[0]=1;
    for(int i=1;i<N;i++) pw[i]=pw[i-1]*2%mod;
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}