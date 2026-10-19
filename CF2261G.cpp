#include<bits/stdc++.h>
#define endl "\n"
#define lowbit(x) (x&(-x))
typedef long long ll;
using namespace std;
const int N=4e5+10,M=(1<<25)+10;
int n,a[N],st[N][21],lg[N],sum[N];
int o,vis[M],cnt[M];
ll num[26],t;
void init()
{
    for(int i=1;i<=n;i++)
        st[i][0]=a[i];
    for(int i=1;i<=20;i++)
        for(int j=1;j<=n-(1<<i)+1;j++)
            st[j][i]=st[j][i-1]&(st[j+(1<<(i-1))][i-1]);
}
int query(int l,int r)
{
    if(l>r)return 0;
    if(l==r)return a[l];
    int len=r-l+1,k=lg[len];
    return st[l][k]&st[r-(1<<k)+1][k];
}
struct node
{
    int i,l,r,A;
};
vector<node> seg; 
struct node1 
{
    int T,k;
};
vector<node1> q[N];
void solve()
{
    cin>>n;
    sum[0]=0;
    seg.clear();
    for(int i=0;i<=25;i++)num[i]=0;
    for(int i=1;i<=n;i++)
        cin>>a[i],sum[i]=sum[i-1]^a[i];
    init();
    for(int i=1;i<=n;i++)
    {
        int L=i;
        while(L<=n)
        {
            int A=query(i,L);
            int l=L,r=n;
            while(l<r)
            {
                int mid=(l+r+1)>>1;
                if(query(i,mid)==A)l=mid;
                else r=mid-1;
            }
            int R=l;
            if(A==0)break;
            seg.push_back({i,L,R,A});
            L=R+1;
            if(L>n)break;
        }
    }
    for(int b=0;b<=25;b++)
    {
        o++;
        for(int i=0;i<=n;i++)
            q[i].clear();
        for(auto [i,l,r,A]:seg)
        {
            int T=(A^sum[i-1])>>b;
            if(A&(1<<b))
            {
                q[l-1].push_back({T,-1});
                q[r].push_back({T,1});
            }
        }
        for(int i=1;i<=n;i++)
        {
            if(vis[sum[i]>>b]!=o)
            {
                vis[sum[i]>>b]=o;
                cnt[sum[i]>>b]=0;
            }
            cnt[sum[i]>>b]++;
            for(auto now:q[i])
                if(vis[now.T]==o)num[b]+=now.k*cnt[now.T];
        }
    }
    ll ans=0;
    for(int i=0;i<=25;i++)
        ans+=(1<<i)*num[i];
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(int i=2;i<N;i++)
        lg[i]=lg[i/2]+1;
    cin>>t;
    while(t--)solve();
    return 0;
}