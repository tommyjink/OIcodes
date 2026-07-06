#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=5e5+100,M=30;
int n,k,L,R,a[N],sum[N],f[N][M+10],d[N][M+10];
struct node
{
    int l,r,val,o,p;
};
bool operator <(node x,node y)
{
    return x.val<y.val;
}
priority_queue<node> q;
int query(int x,int y)
{
    if(x>n)return 0;
    if(y>n)y=n;
    int res=x;
    for(int i=M-1;i>=0;i--)
    {
        if(f[x][i]&&f[x][i]<=y)
        {
            if(sum[d[x][i]]>sum[res])
                res=d[x][i];
            x=f[x][i];
        }
    }
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>k>>L>>R;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
    for(int i=1;i<=n;i++)
    {
        f[i][0]=i+1;
        if(sum[i+1]>=sum[i])d[i][0]=i+1;
        else d[i][0]=i;
    }
    f[n][0]=0;
    for(int j=1;j<M;j++)
    {
        for(int i=1;i<=n;i++)
        {
            f[i][j]=f[f[i][j-1]][j-1];
            if(sum[d[f[i][j-1]][j-1]]>=sum[d[i][j-1]])
                d[i][j]=d[f[i][j-1]][j-1];
            else d[i][j]=d[i][j-1];
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(i+L-1<=n)
        {
            q.push((node){i+L-1,min(i+R-1,n),sum[query(i+L-1,i+R-1)]-sum[i-1],query(i+L-1,i+R-1),i});
            // cout<<i+L-1<<" "<<min(i+R-1,n)<<" "<<sum[query(i+L-1,i+R-1)]-sum[i-1]<<endl;
        }
    }
    int ans=0,cnt=0;
    while(!q.empty()&&++cnt<=k)
    {
        node t=q.top();q.pop();
        // cout<<t.p<<" "<<t.l<<","<<t.r<<":"<<t.val<<endl;
        ans+=t.val;
        if(t.l<=t.o-1)q.push((node){t.l,t.o-1,sum[query(t.l,t.o-1)]-sum[t.p-1],query(t.l,t.o-1),t.p});
        if(t.o+1<=t.r)q.push((node){t.o+1,t.r,sum[query(t.o+1,t.r)]-sum[t.p-1],query(t.o+1,t.r),t.p});
    }
    cout<<ans<<endl;
    return 0;
}