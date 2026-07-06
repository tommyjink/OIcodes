#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=3e5+10;
int n,m,a[N],fa[N],q[N],tot;
int s[N],f[N];
bool key[N];
vector<int> e[N],tmp;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    q[++tot]=1;
    for(int i=1;i<=tot;i++)
    {
        int x=q[i];
        for(auto y:e[x])
            if(y!=fa[x])fa[y]=x,q[++tot]=y;
    }
    bool ok=true;
    for(int i=n;i>=1;i--)
    {
        int x=q[i],sum=0;
        tmp.clear();
        for(auto y:e[x])
        {
            if(fa[y]!=x)continue;
            sum+=s[y];
            f[x]+=f[y];
            if(!key[y])tmp.push_back(s[y]-a[y]);
        }
        sort(tmp.begin(),tmp.end(),greater<int>());
        for(auto y:tmp)
        {
            if(sum<=m)break;
            sum-=y;
            f[x]++;
        }
        if(sum>m)
        {
            ok=false;
            break;
        }
        if(x==1)continue;
        if(a[x]>m)
        {
            ok=false;
            break;
        }
        if(a[x]+sum>m)
        {
            key[x]=true;
            s[x]=a[x];
            f[x]++;
        }
        else s[x]=a[x]+sum;
    }
    // for(int i=1;i<=n;i++)
    //     cout<<s[i]<<" ";
    // cout<<endl;
    if(!ok)cout<<-1<<endl;
    else cout<<f[1]<<endl;
    return 0;
}
