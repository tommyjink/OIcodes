#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e7;
int n,m,q,u,v,t,a[N],b[N],tot=0;
priority_queue<int> pq;
queue<int> q1,q2,q3;
int g()
{
    int res=-1e9;
    if(!q1.empty())res=max(res,q1.front());
    if(!q2.empty())res=max(res,q2.front());
    if(!q3.empty())res=max(res,q3.front());
    if(!q1.empty()&&res==q1.front())q1.pop();
    else if(!q2.empty()&&res==q2.front())q2.pop();
    else if(!q3.empty()&&res==q3.front())q3.pop();
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m>>q>>u>>v>>t;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+1+n,greater<int>());
    for(int i=1;i<=n;i++)
        q1.push(a[i]);
    for(int i=1;i<=m;i++)
    {
        b[i]=g()+tot;
        int x=b[i]*u/v;
        int y=b[i]-x;
        tot+=q;
        x-=tot,y-=tot;
        q2.push(x);
        q3.push(y);
    }
    for(int i=1;i<=m;i++)
        if(i%t==0)cout<<b[i]<<" ";
    cout<<endl;
    int cnt=0;
    while(1)
    {
        int res=g();
        if(res==-1e9)break;
        if(++cnt%t==0)cout<<res+tot<<" ";
    }
    return 0;
}