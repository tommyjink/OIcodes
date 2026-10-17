#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=1e6+10;
int n,p[N],cnt;
struct node{int l,r,mn,mx,cnt1,cnt2;};
int check(node x,node y)
{
    if(x.mx+1==y.mn)return 1;
    else if(x.mn-1==y.mx) return -1;
    return 0;
}
void solve()
{
    cnt=0;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>p[i];
    int ans=0;
    stack<node> s;
    for(int i=1;i<=n;i++)
    {
        node now={i,i,p[i],p[i],0,0};
        int typ=0;
        while(!s.empty()&&(typ=check(s.top(),now)))
        {
            now.l=s.top().l;
            now.mx=max(now.mx,s.top().mx);
            now.mn=min(now.mn,s.top().mn);
            if(typ==1)
            {
                now.cnt1=now.cnt1+s.top().cnt1;
                now.cnt2=now.cnt1+1;
            }
            else
            {
                now.cnt2=now.cnt2+s.top().cnt2;
                now.cnt1=now.cnt2+1;
            }
            s.pop();
        }
        s.push(now);
    }
    if(s.size()>1)cout<<"-1"<<endl;
    else cout<<s.top().cnt1<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}