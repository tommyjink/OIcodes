#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=1e6+10;
int n,a[N],b[N],c[N];
int sum[N];
struct node
{
    int cnt,val;
};
bool operator <(node x,node y)
{
    return x.val<y.val;
}
priority_queue<node> q;
bool check(int cnt)
{
    int now=0;
    while(!q.empty())q.pop();
    for(int i=1;i<=n;i++)
    {
        now+=a[i]-cnt*b[i];
        while(!q.empty()&&(now<0||q.top().val-sum[i]>=c[i]))
        {
            if(q.top().val-sum[i]>=c[i])
            {
                now+=(q.top().val-sum[i])*q.top().cnt;
                cnt+=q.top().cnt;
                q.pop();
            }
            else if(q.top().val-sum[i]>0)
            {
                node t=q.top();q.pop();
                int need=(-now+t.val-sum[i]-1)/(t.val-sum[i]);
                need=min(need,t.cnt);
                t.cnt-=need;
                now+=(t.val-sum[i])*need;
                cnt+=need;
                if(t.cnt)q.push(t);
            }
            else return false;
        }
        if(now<0)return false;
        int tmp=now/c[i];
        tmp=min(tmp,cnt);
        cnt-=tmp;
        now-=tmp*c[i];
        q.push({tmp,c[i]+sum[i]});
    }
    return cnt==0;
}
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i]>>b[i]>>c[i];
    for(int i=1;i<=n;i++)
        sum[i]=sum[i-1]+b[i];
    int l=0,r=1e12;
    while(l<r)
    {
        int mid=(l+r+1)>>1;
        if(check(mid))l=mid;
        else r=mid-1;
    }
    cout<<l<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}