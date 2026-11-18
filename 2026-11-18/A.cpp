#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define ll __int128
#define abs(x) (x<0?-x:x)
#define pii pair<int,int>
using namespace std;
const int N=2e5+10;
int n;
ll t;
vector<int> b;
multiset<pii> s[N];
struct node
{
    int x,b,t;
}a[N];
bool cmp(node x,node y)
{
    if(x.x==y.x)return x.t<y.t;
    return x.x<y.x;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>t;
    for(int i=1;i<=n;i++)
        cin>>a[i].x>>a[i].b>>a[i].t,b.push_back(a[i].t);
    sort(b.begin(),b.end());
    b.erase(unique(b.begin(),b.end()),b.end());
    sort(a+1,a+1+n,cmp);
    int p=b.size()-1,ans=0,nowcnt=0;
    ll nowval=0;
    for(int i=1;i<=n;i++)
    {
        t-=a[i].x-a[i-1].x;
        while(t<0)
        {
            if(p==0&&s[p].empty())
            {
                cout<<ans<<endl;
                return 0;
            }
            if(s[p].empty()){p--;continue;}
            pii q=*s[p].begin();
            int now=(abs(t)+q.first-1)/q.first;
            int mn=min(q.second,now);
            t+=mn*q.first;
            nowcnt-=mn;
            s[p].erase(q);
            if(q.second-now)s[p].insert({q.first,q.second-now});
        }
        ans=max(ans,nowcnt);
        ll tmp=(ll)a[i].b*(ll)a[i].t;
        int k=lower_bound(b.begin(),b.end(),a[i].t)-b.begin();
        if(k<=p)
        {
            nowcnt+=a[i].b;
            t-=a[i].b*a[i].t;
            s[k].insert({a[i].t,now});
        }

    }
    return 0;
}