#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=1e6+10,P=1e9+7,base1=13331,base2=998244353;
int q,l,r,n;
pii hs[N],b[N],ht[N];
string s,t;
map<pii,bool> mp;
map<pii,bool> a;
inline void init(const string &s,pii *h)
{
    int len=s.length();
    for(int i=1;i<len;i++)
        h[i].first=(h[i-1].first*base1%P+(int)s[i])%P;
    for(int i=1;i<len;i++)
        h[i].second=(h[i-1].second*base2%P+(int)s[i])%P;
}
inline pii gethash(int l,int r,pii *h)
{
    pii res;
    res.first=((h[r].first-h[l-1].first*b[r-l+1].first%P)%P+P)%P;
    res.second=((h[r].second-h[l-1].second*b[r-l+1].second%P)%P+P)%P;
    return res;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    b[0].first=b[0].second=1;
    for(int i=1;i<N;i++)
        b[i].first=b[i-1].first*base1%P;
    for(int i=1;i<N;i++)
        b[i].second=b[i-1].second*base2%P;
    cin>>s>>q;
    n=s.length();
    s=" "+s;
    init(s,hs);
    for(int i=1;i<=n;i++)
        for(int j=i;j<=n;j++)
            mp[gethash(i,j,hs)]=true;
    // for(int i=1;i<=n;i++)
    // {
    //     for(int j=i;j<=n;j++)
    //     {
    //         cout<<i<<","<<j<<":"<<gethash(i,j,hs).first<<endl;
    //     }
    // }
    while(q--)
    {
        a.clear();
        cin>>t>>l>>r;
        int m=t.length();
        t=" "+t;
        init(t,ht);
        int res=0;
        for(int i=1;i<=m;i++)
        {
            for(int j=i;j<=m;j++)
            {
                if(a.count(gethash(i,j,ht)))continue;
                if(!mp.count(gethash(i,j,ht)))res++;
                a[gethash(i,j,ht)]=true;
            }
        }
        cout<<res<<endl;
    }
    return 0;
}