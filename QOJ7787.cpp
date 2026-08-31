#include<bits/stdc++.h>
#define int long long
#define lowbit(x) (x&(-x))
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,q,a[N],c[N],d[N],t[N],cnt[N];
vector<int> b;
void add(int *t,int x,int d)
{
    for(int i=x;i<N;i+=lowbit(i))
        t[i]+=d;
}
int query(int *t,int x)
{
    int res=0;
    for(int i=x;i;i-=lowbit(i))
        res+=t[i];
    return res;
}
int fd(int val)
{
    int x=0;
    for(int i=20;i>=0;i--)
        if(x+(1ll<<i)<=b.size()&&t[x+(1ll<<i)]<=val)
            x+=(1ll<<i),val-=t[x];
    return x;
}
int cal(int x)
{
    return lower_bound(b.begin(),b.end(),x)-b.begin()+1;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]>0)b.push_back(a[i]);
    }
    for(int i=1;i<=q;i++)
    {
        cin>>c[i]>>d[i];
        if(d[i]>0)b.push_back(d[i]);
    }
    sort(b.begin(),b.end());
    b.erase(unique(b.begin(),b.end()),b.end());
    int sum=0,num=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]>0)
        {
            int x=cal(a[i]);
            add(t,x,a[i]);
            add(cnt,x,1);
        }
        else
        {
            sum-=a[i];
            num++;
        }
    }
    for(int i=1;i<=q;i++)
    {
        if(a[c[i]]>0)
        {
            int x=cal(a[c[i]]);
            add(t,x,-a[c[i]]);
            add(cnt,x,-1);
        }
        else
        {
            sum+=a[c[i]];
            num--;
        }
        if(d[i]>0)
        {
            int x=cal(d[i]);
            add(t,x,d[i]);
            add(cnt,x,1);
        }
        else
        {
            sum-=d[i];
            num++;
        }
        a[c[i]]=d[i];
        int p=fd(sum),c=query(cnt,p);
        if(p==b.size())cout<<c+1<<endl;
        else
        {
            int ex=(sum-query(t,p))/b[p];
            cout<<c+ex+1<<endl;
        }
    }
    return 0;
}