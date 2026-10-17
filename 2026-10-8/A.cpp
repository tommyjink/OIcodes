#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=1e6+10;
int n,p[N],cnt;
struct node{int l,r,mn,mx,typ;};
vector<node> v[N];
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
    for(int i=0;i<=n;i++)v[i].clear();
    for(int i=1;i<=n;i++)v[cnt].push_back({i,i,p[i],p[i],0});
    int ans=0;
    while(v[cnt].size()>1)
    {
        // cout<<"cnt="<<cnt<<endl;
        // for(node x:v[cnt])cout<<x.l<<","<<x.r<<"_____"<<x.typ<<endl;
        cnt++;
        node now={-1,0,0,0,0},lst={-1,0,0,0,0};
        int typ=0,cnt1=0,cnt2=0,tmp=0;
        for(node p:v[cnt-1])
        {
            if(now.l==-1)
            {
                now=p;
            }
            else if(check(lst,p))
            {
                typ=check(lst,p);
                now.r=p.r;
                now.mx=max(now.mx,p.mx);
                now.mn=min(now.mn,p.mn);
            }
            else
            {
                if(!typ)typ=tmp;
                now.typ=typ;
                v[cnt].push_back(now);
                // cout<<now.l<<","<<now.r<<":"<<cnt1<<","<<cnt2<<endl;
                if(typ==1)ans+=cnt2;
                if(typ==-1)ans+=cnt1;
                now=p;
                typ=0;
                tmp=0;
                cnt1=0,cnt2=0;
            }
            if(p.typ==1)cnt1++;
            if(p.typ==-1)cnt2++;
            lst=p;
            tmp=p.typ;
        }
        if(!typ)typ=tmp;
        now.typ=typ;
        v[cnt].push_back(now);
        // cout<<now.l<<","<<now.r<<":"<<cnt1<<","<<cnt2<<endl;
        if(typ==1)ans+=cnt2;
        if(typ==-1)ans+=cnt1;
        if(v[cnt].size()==v[cnt-1].size())
        {
            cout<<"-1"<<endl;
            return;
        }
    }
    if(v[cnt].back().typ==-1)ans+=1;
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}