#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=3e6+10;
int n,m,a[N],b[N],sum[N];
int tag[N],ans=0,tim[N];
vector<int> c;
struct node{int val,num,tim;};
bool operator <(node x,node y)
{
    return x.val<y.val;
}
priority_queue<node> q;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i],c.emplace_back(a[i]);
    for(int i=1;i<=m;i++)
        cin>>b[i],c.emplace_back(b[i]);
    sort(c.begin(),c.end());
    c.erase(unique(c.begin(),c.end()),c.end());
    int now=0;
    for(int i=1;i<=n;i++)
    {
        a[i]=lower_bound(c.begin(),c.end(),a[i])-c.begin();
        sum[a[i]]+=c[a[i]];
    }
    for(int i=0;i<(int)c.size();i++)
    {
        q.push({sum[i],i,0});
        now+=sum[i];
    }
    for(int i=1;i<=m;i++)
    {
        b[i]=lower_bound(c.begin(),c.end(),b[i])-c.begin();
        sum[b[i]]+=c[b[i]];
        now+=c[b[i]];
        if(tag[b[i]])
        {
            ans+=c[b[i]];
            node t={0,0,0};
            while(!q.empty())
            {
                t=q.top();
                q.pop();
                if(tim[t.num]==t.tim)break;
            }
            ans+=t.val;
            tag[t.num]=true;
        }
        else
        {
            q.push({sum[b[i]],b[i],++tim[b[i]]});
            node t={0,0,0};
            while(!q.empty())
            {
                t=q.top();
                q.pop();
                if(tim[t.num]==t.tim)break;
            }
            ans+=t.val;
            tag[t.num]=true;
        }
        cout<<now-ans<<" ";
    }
    return 0;
}