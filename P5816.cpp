#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define lowbit(x) ((x)&(-x))
#define pii pair<int,int>
using namespace std;
const int N=1e6+10;
int n,t[N];
pii a[N],b[N];
vector<int> X,Y;
vector<pii> A[N],B[N];
void add(int x,int d)
{
    if(x==0)return;
    for(int i=x;i<=n;i+=lowbit(i))
        t[i]+=d;
}
int sum(int x)
{
    int res=0;
    for(int i=x;i;i-=lowbit(i))
        res+=t[i];
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].first>>a[i].second;
        X.push_back(a[i].first);
        Y.push_back(a[i].second);
    }
    sort(X.begin(),X.end());
    sort(Y.begin(),Y.end());
    X.erase(unique(X.begin(),X.end()),X.end());
    Y.erase(unique(Y.begin(),Y.end()),Y.end());
    for(int i=1;i<=n;i++)
    {
        a[i].first=lower_bound(X.begin(),X.end(),a[i].first)-X.begin()+1;
        a[i].second=lower_bound(Y.begin(),Y.end(),a[i].second)-Y.begin()+1;
        b[i].second=a[i].first;
        b[i].first=a[i].second;
    }
    sort(a+1,a+1+n);
    sort(b+1,b+1+n);
    for(int i=2;i<=n;i++)
    {
        if(b[i].first==b[i-1].first&&b[i-1].second+1<b[i].second)
            B[b[i-1].second+1].emplace_back(pii(b[i-1].first,1)),
            B[b[i].second].emplace_back(pii(b[i].first,-1));
    }   
    for(int i=2;i<=n;i++)
    {
        if(a[i].first==a[i-1].first&&a[i-1].second+1<a[i].second)
            A[a[i].first].emplace_back(pii(a[i-1].second+1,a[i].second-1));
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        for(auto j:B[i])
            add(j.first,j.second);
        for(auto j:A[i])
            ans+=sum(j.second)-sum(j.first-1);
    }
    cout<<ans+n<<endl;
    return 0;
}