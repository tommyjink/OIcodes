#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=2000+10;
int n,tag[N],g[N][N];
struct node
{
    int x,y,s;
}a[N];
bool cmp(node x,node y)
{
    return x.y<y.y;
}
int task()
{
    if(n<=20)return 2;
}
void solve2()
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(a[i].y<a[j].y&&max(abs(a[i].x-a[j].x),abs(a[i].y-a[j].y))<=max(a[i].s,a[j].s))
                g[i][j]=true;
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(i!=j&&g[i][k]&&g[k][j])
                    g[i][j]=true;
    for(int i=2;i<=n;i++)
        tag[i]=true;
    for(int i=1;i<(1ll<<n);i++)
    {
        if(__builtin_popcountll(i)<2)continue;
        int cnt=0,v[30]={0},now=false;
        for(int j=1;j<=n;j++)
            if(i&(1ll<<(j-1)))v[++cnt]=j;
        for(int j=1;j<=cnt;j++)
        {
            for(int k=1;k<=cnt;k++)
            {
                if(j!=k&&g[v[j]][v[k]])now=true;
            }
        }
        if(now==false)
        {
            tag[cnt]=false;
        }
    }
    for(int i=2;i<=n;i++)
    {
        if(tag[i])
        {
            cout<<i<<endl;
            return;
        }
    }
    cout<<"-1"<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i].x>>a[i].y>>a[i].s;
    solve2();
    return 0;
}