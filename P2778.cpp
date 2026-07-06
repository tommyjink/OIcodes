#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=8005,M=30;
int n,q,fa[N],vis[N]={true},step[N];
struct node
{
    int x,y,r;
}c[N];
bool operator <(node x,node y)
{
    return x.r<y.r;
}
int f2(int x)
{
    return x*x;
}
int dis2(int x,int y,int xx,int yy)
{
    return f2(x-xx)+f2(y-yy);
}
bool check(int x,int y,int i)
{
    return dis2(x,y,c[i].x,c[i].y)<=f2(c[i].r);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>c[i].x>>c[i].y>>c[i].r;
    cin>>q;
    while(q--)
    {
        int x,y,xx,yy,ans=0;
        cin>>x>>y>>xx>>yy;
        for(int i=1;i<=n;i++)
            if(check(x,y,i)!=check(xx,yy,i))
                ans++;
        cout<<ans<<endl;
    }
    return 0;
}