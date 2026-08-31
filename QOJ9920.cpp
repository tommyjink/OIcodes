#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
struct node
{
    int len,val;
};
int n,a[N],maxa=0;
vector<node> L[N],R[N];
void build(int s,vector<node> &v,int t)
{
    int D=1,r=0,q=0,tag=0,d=0;
    v.clear();
    v.push_back({0,0});
    for(int k=1;k<=n-1;s+=t,k++)
    {
        if(!tag)
        {
            q+=(2*r+a[s])/(2*D);
            r=(2*r+a[s])%(2*D);
            D=D*2;
            if(D>maxa)
            {
                tag=1;
                d=D-r;
            }
        }
        else
        {
            if(a[s]>=2*d)q++,d=maxa;
            else d=2*d-a[s];
        }
        if(v.empty()||v.back().val!=q)
            v.push_back({k,q});
        if(tag&&d>=maxa)break;
    }
}
void solve()
{
    maxa=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i],a[i+n]=a[i],maxa=max(maxa,a[i]);
        L[i].clear(),R[i].clear();
    }
    build(n,L[1],-1);
    build(1,R[n],1);
    for(int i=1;i<=n-1;i++)
    {
        L[i+1].push_back({0,0});
        for(auto j:L[i])
        {
            if(j.len+1>n-1)continue;
            int val=(j.val+a[i])/2;
            if(L[i+1].back().val!=val)
                L[i+1].push_back({j.len+1,val});
        }
    }
    for(int i=n;i>=2;i--)
    {
        R[i-1].push_back({0,0});
        for(auto j:R[i])
        {
            if(j.len+1>n-1)continue;
            int val=(j.val+a[i])/2;
            if(R[i-1].back().val!=val)
                R[i-1].push_back({j.len+1,val});
        }
    }
    for(int i=1;i<=n;i++)
    {
        int p=R[i].size()-1,res=0;
        for(auto j:L[i])
        {
            while(p>=0&&R[i][p].len+j.len+1>n)p--;
            if(p<0)break;
            res=max(res,j.val+R[i][p].val+a[i]);
        }
        cout<<res<<" ";
    }
    cout<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}