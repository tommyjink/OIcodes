#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=205;
int n,b[N],c[N],a[N],d[N];
int fa[N],s[N],t[N],cnt=0;
vector<int> V;
int getfa(int x)
{
    if(x==fa[x])return x;
    return (fa[x]=getfa(fa[x]));
}
void merge(int x,int y)
{
    x=getfa(x);
    y=getfa(y);
    if(x==y)return;
    t[x]=t[y];
    fa[y]=x;
    cnt--;
}
void ask(int n)
{
    cout<<"? ";
    for(int i=1;i<=n;i++)
        cout<<b[i]<<" ";
    cout<<endl;
    for(int i=1;i<=n-1;i++)
        cin>>c[i];
}
void repo()
{
    cout<<"! ";
    for(int i=1;i<=n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}
void con(int l,int r)
{
    int m=r-l;
    for(int i=0;i<=m;i++)
        if(i&1)d[i]=m-i/2;
        else d[i]=i/2;
    for(int now=0;now<=m;now++)
    {
        for(int i=0;i<=m;i++)
            b[i+1]=l+(d[i]+now)%(m+1);
        ask(m+1);
        for(int i=0;i<=m;i++)
            if(c[i+1])merge(b[i+1],b[i+2]);
    }
}
void cal()
{
    for(int i=1;i<=n;i++)
        if(i==fa[i])V.push_back(i);
}
void solve()
{
    cin>>n;
    cnt=n;
    for(int i=1;i<=n;i++)
        fa[i]=s[i]=t[i]=i;
    if(n&1)
    {
        int m=n-1;
        for(int i=0;i<=m;i++)
            if(i&1)d[i]=m-i/2;
            else d[i]=i/2;
        for(int now=0;now<=m;now++)
        {
            b[1]=1;
            for(int i=0;i<=m;i++)
                b[i+2]=2+(d[i]+now)%(m+1);
            ask(n);
            for(int i=0;i<=n;i++)
                if(c[i+1])merge(b[i+1],b[i+2]);
        }
        cal();
        if(cnt==2)
        {
            
        }
    }
    else
    {

    }
}
signed main()
{
    int t;cin>>t;
    while(t--)solve();
    return 0;
}