#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int INF=1e16;
int n;
struct node
{
    int x=0,y=INF;//x/y
}ans;
bool operator <(node a,node b)
{
    return a.x*b.y<a.y*b.x;
}
void dfs(int now,int k,node a)
{   
    if(now==k)
    {
        ans=max(ans,a);
        return;
    }
    dfs(now+1,k,{a.x+1,a.y});
    if(a.y>1)dfs(now+1,k,{a.x,a.y-1});
}
void query(int x,int k)
{
    ans.x=0,ans.y=INF;
    dfs(0,k,{1,x});
    cout<<ans.x<<"/"<<ans.y<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(int i=1;i<=20;i++)
    {
        for(int j=1;j<=i*2;j++)
        {
            cout<<"(x,k)="<<i<<","<<j<<endl;
            query(i,j);
        }
    }
    return 0;
}