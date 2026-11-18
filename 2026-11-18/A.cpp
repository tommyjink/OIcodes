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
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    int tt;
    cin>>n>>tt;
    t=tt;
    for(int i=1;i<=n;i++)
        cin>>a[i].x>>a[i].b>>a[i].t,b.push_back(a[i].t);
    sort(b.begin(),b.end());
    b.erase(unique(b.begin(),b.end()),b.end());
    sort(a+1,a+1+n,cmp);
    int p=b.size()-1,ans=0,nowcnt=0;
    for(int i=1;i<=n;i++)
    {
        t-=a[i].x-a[i-1].x;
        int k=lower_bound(b.begin(),b.end(),a[i].t)-b.begin();
        if(k<=p)
        {
            nowcnt+=a[i].b;
            t-=(ll)a[i].b*(ll)a[i].t;
            s[k].insert({a[i].t,a[i].b});
        }
        while(t<0)
        {
            // cout<<(int)(t<0)<<","<<(int)t<<endl;
            if(p==0&&s[p].empty())
            {
                cout<<ans<<endl;
                return 0;
            }
            if(s[p].empty()){p--;continue;}
            pii q=*s[p].begin();
            ll now=(abs(t)+q.first-1)/q.first;
            ll mn=min((ll)q.second,now);
            t+=mn*q.first;
            nowcnt-=mn;
            s[p].erase(s[p].begin());
            if(q.second-mn>0)s[p].insert({q.first,q.second-mn});
        }
        ans=max(ans,nowcnt);
    }
    cout<<ans<<endl;
    return 0;
}