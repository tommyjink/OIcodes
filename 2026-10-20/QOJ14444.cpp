#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e5+10;
int n,p[N],w[N],tag[N];
double sum=0.0;
struct node
{
    int p,id;
    double w;
};
bool operator <(node x,node y)
{
    if(x.w==y.w)return x.id>y.id;
    return x.w<y.w;
}
priority_queue<node> q;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    p[0]=-1e9;
    p[n+1]=1e9;
    for(int i=1;i<=n;i++)
    {
        cin>>p[i]>>w[i];
        sum+=p[i]*w[i]*1.0;
    }
    for(int i=1;i<=n;i++)
        q.push({p[i],i,w[i]*1.0});
    while(sum)
    {
        while(tag[q.top().id])q.pop();
        node t=q.top();q.pop();
        
    }
    return 0;
}