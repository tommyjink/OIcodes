#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,tot=0,head[N],in[N],b=0,c[N];
struct node
{
    int to,next;
}e[N*2];
struct Point
{
    int x,y,z;
};
void add(int x,int y)
{
    e[++tot]=(node){y,head[x]};
    head[x]=tot;
}
void dfs(int x,int fa)
{
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(v==fa)continue;
        if(in[x]==2&&!b)
            b=true,c[v]=c[x];
        else c[v]=c[x]^1;
        dfs(v,x);
    }
}
void print(int x,int fa)
{
    if(x!=1&&c[x])cout<<x<<" "<<fa<<endl;
    else if(x!=1)cout<<fa<<" "<<x<<endl;
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(v==fa)continue;
        print(v,x);
    }
}
void solve()
{
    cin>>n;
    tot=b=0;
    for(int i=1;i<=n;i++)
        head[i]=in[i]=c[i]=0;
    for(int i=1;i<=n-1;i++)
    {
        int x,y;
        cin>>x>>y;
        add(x,y);
        add(y,x);
        in[x]++;
        in[y]++;
    }
    int tag=false;
    for(int i=1;i<=n;i++)
        if(in[i]==2)tag=true;
    if(!tag)
    {
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
    dfs(1,0);
    print(1,0);
    // for(int i=1;i<=n;i++)
    //     cout<<c[i]<<" ";
    // cout<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}
/*
4  
5  
1 2  
2 4  
1 3  
3 5  
5  
1 2  
1 3  
1 4  
4 5  
2  
1 2  
4  
1 3  
2 1  
2 4  
*/