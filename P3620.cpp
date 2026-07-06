#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,k,a[N],b[N],l[N],r[N],tag[N],ans=0,typ[N];
priority_queue<pii,vector<pii>,greater<pii>> q;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {

        cin>>b[i];
        if(i>1)
        {
            a[i-1]=b[i]-b[i-1],l[i-1]=i-2,r[i-1]=i;
            q.push(make_pair(a[i-1],i-1));
        }
    }
    n--;
    a[0]=a[n+1]=1e15;
    for(int i=1;i<=k;i++)
    {
        while(!q.empty()&&tag[q.top().second])q.pop();
        int t=q.top().second;q.pop();
        ans+=a[t];
        tag[l[t]]=tag[r[t]]=1;
        a[t]=a[l[t]]+a[r[t]]-a[t];
        l[t]=l[l[t]];
        r[t]=r[r[t]];
        l[r[t]]=t,r[l[t]]=t;
        q.push(make_pair(a[t],t));
    }
    cout<<ans<<endl;
    return 0;
}