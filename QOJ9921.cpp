#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=2e6+10;
int n,nxt[N][30],vis[N][30],tim=0;
int tot=0,cnt[N],ans=0,f[N];
string s[N];
vector<int> d[N];
void upd(int x)
{
    ans^=f[x]*x;
    f[x]++;
    ans^=f[x]*x;
}
void add(string s)
{
    int n=s.length(),p=0;
    for(int i=0;i<n;i++)
    {
        int c=s[i]-'a';
        if(vis[p][c]!=tim)
            vis[p][c]=tim,
            nxt[p][c]=++tot,
            cnt[tot]=0;
        p=nxt[p][c];
        cnt[p]++;
        for(int j:d[cnt[p]])upd(j);
    }
}
void solve()
{
    tim++;
    tot=ans=0;
    cin>>n;
    for(int i=1;i<=n;i++)f[i]=0;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
        add(s[i]);
        cout<<ans<<" ";
    }
    cout<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(int i=1;i<N;i++)
        for(int j=i;j<N;j+=i)
            d[j].push_back(i);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}