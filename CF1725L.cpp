#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define lowbit(x) ((x)&(-x))
using namespace std;
const int N=1e6+10;
int n,a[N],t[N];
vector<int> b;
void add(int x,int d)
{
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
    int mx=-1e18;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        a[i]+=a[i-1];
        mx=max(mx,a[i]);
        b.emplace_back(a[i]);
        if(a[i]<0)
        {
            cout<<"-1"<<endl;
            return 0;
        }
    }
    if(a[n]!=mx)
    {
        cout<<"-1"<<endl;
        return 0;
    }
    sort(b.begin(),b.end());
    b.erase(unique(b.begin(),b.end()),b.end());
    for(int i=1;i<=n;i++)
        a[i]=lower_bound(b.begin(),b.end(),a[i])-b.begin()+1;
    int ans=0;
    for(int i=n;i>=1;i--)
    {
        ans+=sum(a[i]-1);
        add(a[i],1);
    }
    cout<<ans<<endl;
    return 0;
}