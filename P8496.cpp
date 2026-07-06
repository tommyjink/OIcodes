#include<bits/stdc++.h>
#define pii pair<int,int>
#define endl "\n"
#define int long long
using namespace std;
const int N=2e6+10;
int n,q,cnt=0,num[N],b[N];
struct node
{
    list<int>l;
    map<int,int>mp;
    set<pii> s;
}a[N];
void insert(int x,int y,int mode)
{
    // x=num[x];
    if(mode)a[x].l.push_back(y);
    else a[x].l.push_front(y);
    if(!a[x].mp.count(y))
    {
        a[x].mp[y]=1;
        a[x].s.insert(pii(1,y));
    }
    else
    {
        a[x].s.erase(pii(a[x].mp[y],y));
        a[x].mp[y]++;
        a[x].s.insert(pii(a[x].mp[y],y));
    }
}
void delback(int x)
{
    // x=num[x];
    int y=a[x].l.back();
    a[x].l.pop_back();
    a[x].s.erase(pii(a[x].mp[y],y));
    a[x].mp[y]--;
    a[x].s.insert(pii(a[x].mp[y],y));
}
void delfront(int x)
{
    // x=num[x];
    int y=a[x].l.front();
    a[x].l.pop_front();
    a[x].s.erase(pii(a[x].mp[y],y));
    a[x].mp[y]--;
    a[x].s.insert(pii(a[x].mp[y],y));
}
int solve(int l,int r)
{
    if(l==r)
    {
        int x=num[b[l]];
        if(a[x].s.empty())return -1;
        int y=a[x].s.rbegin()->second;
        if(a[x].mp[y]*2>a[x].l.size())return y;
        else return -1;
    }
    int mid=(l+r)>>1;
    int res1=solve(l,mid);
    int res2=solve(mid+1,r);
    if(res1==-1&&res2==-1)return -1;
    int cnt1=0,cnt2=0,len=0;
    for(int i=l;i<=r;i++)
    {
        int x=num[b[i]];
        if(res1!=-1)cnt1+=a[x].mp[res1];
        if(res2!=-1)cnt2+=a[x].mp[res2];
        len+=a[x].l.size();
    }
    if(res1!=-1&&cnt1*2>len)return res1;
    if(res2!=-1&&cnt2*2>len)return res2;
    return -1;
}
int query()
{
    int m;
    cin>>m;
    for(int i=1;i<=m;i++)
        cin>>b[i];
    return solve(1,m);
}
void merge(int x,int y,int z)
{
    x=num[x];
    y=num[y];
    if(a[x].l.size()<a[y].l.size())
    {
        num[z]=y;
        while(!a[x].l.empty())
        {
            int now=a[x].l.back();
            // delback(x);
            a[x].l.pop_back();
            insert(y,now,0);
        }
    }
    else
    {
        num[z]=x;
        while(!a[y].l.empty())
        {
            int now=a[y].l.front();
            // delfront(y);
            a[y].l.pop_front();
            insert(x,now,1);
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        int m;
        cin>>m;
        num[i]=++cnt;
        for(int j=1;j<=m;j++)
        {
            int x;
            cin>>x;
            insert(num[i],x,1);
        }
    }
    while(q--)
    {
        int op;
        cin>>op;
        if(op==1)
        {
            int x,y;
            cin>>x>>y;
            insert(num[x],y,1);
        }
        else if(op==2)
        {
            int x;
            cin>>x;
            delback(num[x]);
        }
        else if(op==3)
        {
            cout<<query()<<endl;
        }
        else 
        {
            int x,y,z;
            cin>>x>>y>>z;
            merge(x,y,z);
        }
        // for(int i=1;i<=cnt;i++)
        // {
        //     int x=num[i];
        //     cout<<x<<":"<<endl;
        //     if(x&&a[x].l.size())
        //     {
        //         for(auto j:a[x].l)
        //             cout<<j<<" ";
        //     }
        //     cout<<endl;
        // }
    }
    return 0;
}