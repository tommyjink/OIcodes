#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=2e6+100;
int n,a[N],l[N],r[N],tag[N],ans[N];
string s;
priority_queue<pii,vector<pii>,greater<pii> > q;
void solve()
{
    
    cin>>n>>s;
    s=" "+s;
    l[0]=r[0]=0;
    a[0]=1e16;
    while(!q.empty())q.pop();
    for(int i=1;i<=n-1;i++)
    {
        if(s[i]=='R'&&s[i+1]=='S')a[i]=0;
        if(s[i]=='S'&&s[i+1]=='R')a[i]=2;
        if(s[i]=='R'&&s[i+1]=='R')a[i]=1;
        if(s[i]=='S'&&s[i+1]=='S')a[i]=1;
        l[i]=i-1,r[i]=i+1;
        q.push({a[i],i});
        ans[i]=0;
    }
    l[1]=r[n-1]=0;
    int now=0,m=0,nn=n;
    for(int i=1;i<=nn/2;i++)
    {
        while(!q.empty()&&tag[q.top().second])q.pop();
        if(q.empty())break;
        pii t=q.top();q.pop();
        tag[t.second]=tag[l[t.second]]=tag[r[t.second]]=1;
        now+=t.first;
        ans[i]=now;
        m=i;
        a[++n]=a[l[t.second]]+a[r[t.second]]-t.first;
        q.push({a[n],n});
        l[n]=l[l[t.second]];
        r[n]=r[r[t.second]];
        r[l[n]]=n;
        l[r[n]]=n;
    }
    int p=0;
    for(int i=0;i<=nn;i++)
    {
        while(p<=m&&ans[p]<=i)p++;
        if(p)p--;
        cout<<p<<" ";
    }
    cout<<endl;
    for(int i=0;i<=n;i++)tag[i]=0;

}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}