#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n;
signed a[N],rk[N],pos[N],st[N],fa[N],cnt[N];
vector<signed> g[N];
pair<signed,signed> b[N/2];
int find(int x)
{
    while(fa[x]!=x)
    {
        fa[x]=fa[fa[x]];
        x=fa[x];
    }
    return x;
}
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>b[i].first;
        b[i].second=i;
    }
    sort(b+1,b+n+1);
    for(int i=1;i<=2*n+1;i++)
        g[i].clear(),cnt[i]=0,fa[i]=i;
    int tot=0;
    for(int l=1,r;l<=n;l=r+1)
    {
        r=l;
        while(r<n&&b[r+1].first==b[l].first)r++;
        int m=r-l+1;
        tot++;
        for(int i=1;i<=m;i++)
            pos[i]=b[l+i-1].second,pos[i+m]=pos[i]+n;
        pos[2*m+1]=2*n+1;
        int top=1;
        st[top]=2*m+1;
        for(int i=2*m;i>=1;i--)
        {
            int x=pos[i];
            a[x]=tot,rk[x]=i;
            while(top&&pos[st[top]]-2*st[top]<pos[i]-2*i)top--;
            if(top)
            {
                int y=x+2*(st[top]-i);
                g[y].push_back(x);
            }
            st[++top]=i;
        }
    }
    int ans=n,p=1;
    for(int r=1;r<=2*n;r++)
    {
        if(r>1)cnt[a[r-1]]++;
        for(int i:g[r])fa[i]=r;
        if(r<=n)continue;
        int x=find(r-n),res=0;
        if(x<r)
            res=2*(cnt[a[x]]-rk[x]+1)-(r-x);
        if(res<ans)ans=res,p=r-n;
    }
    cout<<ans<<" "<<p<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}
