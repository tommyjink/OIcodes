#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,a[N],nxt[N],rnk[N],len[N];
vector<int> v[N];
struct node{int id,len,nxt;};
bool cmp(node x,node y)
{
    if(x.len!=y.len)return x.len<y.len;
    return x.nxt<y.nxt;
}
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i],a[i+n]=a[i],v[a[i]].push_back(i);
    stack<int> s;
    for(int i=2*n;i>=1;i--)
    {
        while(!s.empty()&&a[s.top()]<=a[i])s.pop();
        if(!s.empty()&&i<=n)nxt[i]=(s.top()-1)%n+1,len[i]=s.top()-i;
        else if(i<=n)nxt[i]=0,len[i]=n;
        s.push(i);
    }   
    int now=0,ans=1;
    for(int i=n;i>=1;i--)
    {   
        vector<node> g;
        for(int j:v[i])g.push_back({j,len[j],rnk[nxt[j]]});
        sort(g.begin(),g.end(),cmp);
        for(auto j:g)rnk[j.id]=++now,ans=j.id;
    }
    now=0;
    for(int i=ans;i<=ans+n-1;i++)
        now=max(now,a[i]),cout<<now<<" ";
    cout<<endl;
    for(int i=1;i<=n;i++)v[i].clear();
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}