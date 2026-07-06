#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int n,q,tag[3][50];
struct node
{
    int m[50];
    void init(){for(int i=0;i<50;i++)m[i]=0;}
}s,f[3][50];
node operator ^(node x,node y)
{
    node res;res.init();
    for(int i=0;i<50;i++)
    {
        res.m[i]=x.m[i]+y.m[i];
        if(res.m[i]>=3)res.m[i]-=3;
    }
    return res;
}
node cal(int x)
{
    node res;res.init();
    for(int i=0;i<50;i++)
    {
        res.m[i]=x%3;
        x/=3;
    }
    return res;
}
void insert(node x)
{
    for(int i=49;i>=0;i--)
    {
        if(!x.m[i])continue;
        if(tag[x.m[i]][i]&&tag[3-x.m[i]][i])
        {
            x=x^f[3-x.m[i]][i];
        }
        else if(!tag[x.m[i]][i]&&tag[3-x.m[i]][i])
        {    
            tag[x.m[i]][i]=true,f[x.m[i]][i]=x,x=x^f[3-x.m[i]][i];
        }
        else if(tag[x.m[i]][i]&&!tag[3-x.m[i]][i])
        {
            tag[3-x.m[i]][i]=true,f[3-x.m[i]][i]=x^f[x.m[i]][i];
            break;
        }
        else 
        {
            tag[x.m[i]][i]=true,f[x.m[i]][i]=x;
            break;
        }
    }
}
bool check(node x)
{
    for(int i=49;i>=0;i--)
    {
        if(!x.m[i])continue;
        if(!tag[3-x.m[i]][i])break;
        x=x^f[3-x.m[i]][i];
    }
    for(int i=49;i>=0;i--)
        if(x.m[i])return false;
    return true;
}
void solve()
{
    memset(tag,0,sizeof(tag));
    for(int i=0;i<3;i++)
        for(int j=0;j<50;j++)
            f[i][j].init();
    s.init();
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        int x;node y;
        cin>>x;y=cal(x);
        insert(y);
        insert(y^y);
    }
    while(q--)
    {
        int x;
        cin>>x;
        if(check(cal(x)))cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}