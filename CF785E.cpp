#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10,M=1e3+10;
int n,q,a[N],len,ans=0;
vector<int> b[M];
inline int id(int x){return (x+len-1)/len;}
inline int L(int id){return (id-1)*len+1;}
inline int R(int id){return id*len;}
inline int query(int l,int r,int x)
{
    if(l>r)return 0;
    int res=0;
    if(id(l)==id(r))
    {
        for(int i=l;i<=r;i++)
            if(a[i]<x)res++;
        return res;
    }
    for(int i=l;i<=R(id(l));i++)
        if(a[i]<x)res++;
    for(int i=id(l)+1;i<=id(r)-1;i++)
        res+=lower_bound(b[i].begin(),b[i].end(),x)-b[i].begin();
    for(int i=L(id(r));i<=r;i++)
        if(a[i]<x)res++;
    return res;
}
inline void update(int x)
{
    b[x].clear();
    for(int i=L(x);i<=R(x);i++)
        b[x].emplace_back(a[i]);
    sort(b[x].begin(),b[x].end());
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>q;
    len=sqrt(n);
    for(int i=1;i<=n;i++)
        a[i]=i,b[id(i)].emplace_back(i);
    for(int i=1;i<=q;i++)
    {
        int l,r;
        cin>>l>>r;
        if(l>r)swap(l,r);
        int ll=a[l],rr=a[r];
        int s1=query(l+1,r-1,rr),s2=query(l+1,r-1,ll);
        ans=ans+s1-s2+(r-l-1-s2)-(r-l-1-s1);
        if(ll>rr)ans--;
        else if(ll<rr) ans++;
        swap(a[l],a[r]);
        update(id(l));
        update(id(r));
        cout<<ans<<endl;
    }
    return 0;
}