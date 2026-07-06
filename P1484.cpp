#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,k,a[N],l[N],r[N],tag[N],ans=0;
priority_queue<pii> q;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        l[i]=i-1,r[i]=i+1;
        q.push(make_pair(a[i],i));
    }
    l[1]=r[n]=0;
    for(int i=1;i<=k;i++)
    {
        while(!q.empty()&&tag[q.top().second])
            q.pop();
        if(q.empty()||q.top().first<0)break;
        pii t=q.top();q.pop();
        ans+=t.first;
        tag[t.second]=tag[l[t.second]]=tag[r[t.second]]=true;

        a[++n]=a[l[t.second]]+a[r[t.second]]-a[t.second];
        l[n]=l[l[t.second]];
        r[n]=r[r[t.second]];
        r[l[n]]=n,l[r[n]]=n;
        q.push(make_pair(a[n],n));
    }
    cout<<ans<<endl;
    return 0;
}