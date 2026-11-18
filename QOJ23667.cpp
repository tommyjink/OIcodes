#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=205;
int n,b[N],c[N],d[N];
int fa[N],s[N],t[N],cnt=0;
int l[N],r[N],num=0;
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
    r[t[x]]=s[y];
    l[s[y]]=t[x];
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
    string s;
    cin>>s;
    for(int i=1;i<=n-1;i++)
    {
        c[i]=s[i-1]-'0';
        if(c[i])merge(b[i],b[i+1]);
    }
}
void repo()
{
    cout<<"! ";
    for(int i=1;i<=n;i++)
        cout<<b[i]<<" ";
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
    }
}
void cal()
{
    for(int i=1;i<=n;i++)
        if(i==fa[i])V.push_back(i);
}
void push(int x)
{
    x=s[getfa(x)];
    b[++num]=x;
    while(x!=r[x])x=r[x],b[++num]=x;
}
void solve()
{
    cin>>n;
    V.clear();
    cnt=n;
    for(int i=1;i<=n;i++)
        fa[i]=s[i]=t[i]=l[i]=r[i]=i;
    if(n&1)
    {
        int m=n-2;
        for(int i=0;i<=m;i++)
            if(i&1)d[i]=m-i/2;
            else d[i]=i/2;
        for(int now=0;now<=m;now++)
        {
            b[1]=1;
            for(int i=0;i<=m;i++)
                b[i+2]=2+(d[i]+now)%(m+1);
            ask(n);
        }
        cal();
        if(cnt==2)
            merge(V[1],V[0]);
    }
    else
    {
        int m=n-3;
        for(int i=0;i<=m;i++)
            if(i&1)d[i]=m-i/2;
            else d[i]=i/2;
        for(int now=0;now<=m;now++)
        {
            b[1]=1;
            b[n]=n;
            for(int i=0;i<=m;i++)
                b[i+2]=2+(d[i]+now)%(m+1);
            ask(n);
        }//2 4 3 1
        cal();
        if(cnt==4)
        {
            int x=1,p=0,q=0,y=n;
            for(int i=0;i<4;i++)
            {
                if(getfa(V[i])!=getfa(1)&&getfa(V[i])!=getfa(n))
                {
                    if(!p)p=V[i];
                    else q=V[i];
                }
            }
            num=0;
            push(p);
            push(x);
            push(y);
            push(q);
            ask(n);
            if(cnt!=1)
            {
                merge(q,x);
                merge(x,y);
                merge(y,p);
            }
        }
        else if(cnt==3)
        {
            if(getfa(1)==getfa(n))
            {
                int x=1,p=V[1],q=V[2];
                num=0;//3 1 4 2 5
                push(p);
                push(x);
                push(q);
                ask(n);
                if(cnt!=1)
                {   
                    merge(q,x);
                    merge(x,p);
                }
            }
            else
            { 
                int x=1,p=0,y=n;
                for(int i=0;i<=2;i++)
                    if(getfa(V[i])!=getfa(1)&&getfa(V[i])!=getfa(n))
                        p=V[i];
                num=0;
                push(x);
                push(y);
                push(p);
                ask(n);
                if(cnt!=1)
                {
                    merge(p,x);
                }
            }
        }
        else if(cnt==2)
        {
            if(n==2)
            {
                b[1]=1,b[2]=2;
                ask(2);
                if(cnt==2)merge(2,1);
            }
            else if(getfa(1)==getfa(n))
            {
                int x=1,p=V[1];
                num=0;
                push(x);
                push(p);
                ask(n);
                if(cnt!=1)
                {
                    merge(p,x);
                }
            }
            else
            {
                merge(n,1);
            }
        }
    }
    num=0;
    push(1);
    repo();
}
signed main()
{
    int t;cin>>t;
    while(t--)solve();
    return 0;
}