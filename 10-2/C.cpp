#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=1e6+10,P=998244353;
int n,a[N],b[N],c[N],d[N],pos[N],e[N];
vector<pii> req;
void solve()
{
    req.clear();
    cin>>n;
    a[0]=b[0]=a[n+1]=b[n+1]=-1;
    for(int i=0;i<=n;i++)
        c[i]=pos[i]=-1;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        cin>>b[i];

    for(int i=1;i<=n;i++)
        if(a[i]!=a[i-1])c[i]=a[i];
    for(int i=n;i>=1;i--)
        if(b[i]!=b[i+1])c[i]=b[i];
    // for(int i=1;i<=n;i++)
    //     cout<<c[i]<<" ";
    // cout<<endl;
    for(int i=1;i<=n;i++)
        if(c[i]!=-1)pos[c[i]]=i;
    e[n]=0;
    for(int i=n-1;i>=0;i--)
        e[i]=(pos[i]==-1)+e[i+1];
    int cnt=1,lp=1,now=0;
    while(lp<=n)
    {
        if(c[lp]!=-1){lp++;continue;}
        int rp=lp;
        while(rp<n&&c[rp+1]==-1)rp++;
        req.push_back(pii(max(a[lp],b[rp]),rp-lp+1));
        lp=rp+1;
    }
    sort(req.begin(),req.end(),greater<pii>());
    for(auto x:req)
    {
        // printf("x.f=%lld,x.s=%lld,e[x.first]=%lld\n",x.first,x.second,e[x.first]);
        for(int i=e[x.first]-now;i>=e[x.first]-now-(x.second-1);i--)
            cnt=cnt*i%P;
        now+=x.second;
    }
    // cout<<cnt<<endl;
    int l=n,r=1,ans=0;
    for(int i=0;i<n;i++)
    {
        if(pos[i]!=-1)
        {
            l=min(l,pos[i]);
            r=max(r,pos[i]);
        }
        // cout<<i<<":"<<l<<","<<r<<endl;
        ans=(ans+l*(n-r+1)%P)%P;
    }
    cout<<ans*cnt%P<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int __t;
    cin>>__t;
    while(__t--)
        solve();
    return 0;
}