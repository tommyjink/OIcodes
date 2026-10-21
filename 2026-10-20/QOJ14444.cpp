#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e5+10;
int n,p[N],w[N],l[N],dis[N];
double sum=0.0;
struct node
{
    double dis,w;
};
bool operator <(node x,node y)
{
    return x.w<y.w;
}
set<node> q;
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
    if(sum>0)
    {
        for(int i=1;i<=n;i++)
            q.insert({1.0*(p[i]-p[i-1]),1.0*w[i]});
    }
    else
    {
        sum=-sum;
        for(int i=1;i<=n;i++)
            q.insert({1.0*(p[i+1]-p[i]),1.0*w[i]});
    }
    double ans=0.0;
    while(!q.empty())
    {
        node t=q.rbegin();
        double now=min(t.dis,sum/t.w);
        ans+=now;
        if(t.dis*t.w>sum)
        {
            printf("%.6lf",t.dis);
            return 0;
        }
        else
        {
            sum-=now*t.w;

        }
    }
    return 0;
}