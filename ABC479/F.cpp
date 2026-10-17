#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,s[N],t[N],cnta=0,cntb=0;
int c[N],cntc=0,lg[N];
struct node
{
    int l,r;
}a[N],b[N];
struct ST
{
    int a[N][21],b[N];
    void init()
    {   
        for(int i=1;i<=n-1;i++)
            a[i][0]=max(b[i],b[i+1]);
        a[n][0]=b[n];
        for(int i=1;i<=20;i++)
            for(int j=1;j<=n;j++)
                a[j][i]=max(a[j][i-1],a[j+(1ll<<(i-1))][i-1]);
    }
    int query(int l,int r)
    {
        if(l==r)return 
    }
}d;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    lg[1]=0;
    lg[2]=1;
    for(int i=2;i<N;i++)
        lg[i]=lg[i/2]+1;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>s[i];
    for(int i=1;i<=n;i++)cin>>t[i];
    int ans=0;
    for(int i=1;i<=n;i++)
        ans+=abs(s[i]-t[i]);
    for(int i=1;i<=n;i++)
    {
        if(s[i]<t[i])a[++cnta]={s[i],t[i]};
        else if(s[i]>t[i]) b[++cntb]={t[i],s[i]};
        else c[++cntc]=s[i];
    }

    return 0;
}