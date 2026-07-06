#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define lowbit(x) x&(-x)
using namespace std;
const int N=1e6+10;
int n,b[N],c[N],tag[N],t[N];
struct node
{
    int x,y;
}a[N];
vector<int> v[N];
bool cmp(node x,node y)
{
    return x.y==y.y?x.x<y.x:x.y>y.y;
}
void add(int x,int d)
{  
    for(int i=x;i<=n;i+=lowbit(i))
        t[i]+=d;
}
int query(int x)
{
    int res=0;
    for(int i=x;i;i-=lowbit(i))
        res+=t[i];
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].x>>a[i].y;
        b[i]=a[i].y;
        c[i]=a[i].x;
    }
    sort(a+1,a+1+n,cmp);
    sort(b+1,b+1+n);
    sort(c+1,c+1+n);
    int totb=unique(b+1,b+1+n)-b-1;
    int totc=unique(c+1,c+1+n)-c-1;
    for(int i=1;i<=n;i++)
        a[i].y=lower_bound(b+1,b+1+totb,a[i].y)-b,
        a[i].x=lower_bound(c+1,c+1+totc,a[i].x)-c;
    // for(int i=1;i<=n;i++)
    //     cout<<a[i].x<<","<<a[i].y<<endl;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(!tag[a[i].x])add(a[i].x,1);
        tag[a[i].x]=true;
        int r=n;
        if(a[i+1].y==a[i].y)r=a[i+1].x-1;
        int x=query(a[i].x),y=query(r)-x+1;
        ans+=x*y;
        // cout<<x*y<<"!"<<endl;
    }
    cout<<ans<<endl;
    return 0;
}
/*
5
3 6
5 10
4 3
2 1
1 3

*/