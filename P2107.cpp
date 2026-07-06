#include<bits/stdc++.h>
#define endl "\n"
#define int long long
using namespace std;
const int N=1e5+100;
int n,m,t[N],vis[N],t1[N],t2[N],ans=0;
struct node
{
    int x,t,num;
}a[N];
bool cmp(node x,node y)
{
    return x.x<y.x;
}
int lowbit(int x)
{
    return x&(-x);
}
void add(int *t,int x,int d)
{
    for(int i=x;i<=n;i+=lowbit(i))
        t[i]+=d;
}
int query(int *t,int x)
{
    int res=0;
    for(int i=x;i>0;i-=lowbit(i))
        res+=t[i];
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].x>>a[i].t;
        t[++t[0]]=a[i].t;
    }
    sort(a+1,a+1+n,cmp);
    sort(t+1,t+1+n);
    for(int i=1;i<=n;i++)
    {
        a[i].t=lower_bound(t+1,t+1+n,a[i].t)-t;
        while(vis[a[i].t])a[i].t++;
        vis[a[i].t]=true;
        // cout<<a[i].x<<" "<<a[i].t<<endl;
    }
    for(int i=1;i<=n;i++)
    {
        add(t1,a[i].t,1);
        add(t2,a[i].t,t[a[i].t]);
        int k=m-a[i].x;
        if(k<0)break;
        int l=0,r=n;
        while(l<r)
        {
            int mid=(l+r+1)>>1;
            if(query(t2,mid)>k)
                r=mid-1;
            else l=mid;
        }
        ans=max(ans,query(t1,l));
    }
    cout<<ans<<endl;
    return 0;
}