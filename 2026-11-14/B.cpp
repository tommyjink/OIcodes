#include<bits/stdc++.h>
#define endl "\n"
#define ls(x) t[x].l
#define rs(x) t[x].r
#define ll long long
using namespace std;
const int N=2e6+10;
int n,m,tot;
int rt,x,y,z,zz;
ll a[N],b[N],sum[N];
vector<int> c;
struct node
{
    int l,r;
    ll val;
    int pri,siz;
    ll sum;
}t[N*10];
inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = (x << 1) + (x << 3) + (ch ^ 48);
        ch = getchar();
    }
    return x * f;
}
inline void write(ll x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
}
inline void pushup(int k)
{
    t[k].siz=t[ls(k)].siz+t[rs(k)].siz+1;
    t[k].sum=t[ls(k)].sum+t[rs(k)].sum+t[k].val;
}
inline int newnode(ll val)
{
    t[++tot]=(node){0,0,val,rand(),1,val};
    return tot;
}
void split(int k,int &x,int &y,ll val)
{
    if(!k){x=y=0;return;}
    if(t[k].val<=val)
    {
        x=k;
        split(rs(x),rs(x),y,val);
        pushup(x);
    }
    else
    {
        y=k;
        split(ls(y),x,ls(y),val);
        pushup(y);
    }
}
int merge(int x,int y)
{
    if(!x||!y)return x+y;
    if(t[x].pri<t[y].pri)
    {
        rs(x)=merge(rs(x),y);
        pushup(x);
        return x;
    }
    else
    {
        ls(y)=merge(x,ls(y));
        pushup(y);
        return y;
    }
}
inline void insert(ll val)
{
    split(rt,x,y,val);
    rt=merge(x,merge(newnode(val),y));
}
inline void del(ll val)
{
    split(rt,x,y,val-1);
    split(y,y,z,val);
    y=merge(ls(y),rs(y));
    rt=merge(merge(x,y),z);
}
ll query(int siz)
{
    int k=rt;
    ll res=0;
    while(k)
    {
        int now=t[ls(k)].siz+1;
        if(now==siz)return res+t[ls(k)].sum+t[k].val;
        else if(now<siz)
        {
            res+=t[ls(k)].sum+t[k].val;
            siz-=now;
            k=rs(k);
        }
        else
        {
            k=ls(k);
        }
    }
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(time(0));
    while(0)
    {
        int op,x;
        cout<<"1.insert\n2.del\n3.query\n";
        cin>>op>>x;
        if(op==1)
        {
            insert(x);
        }
        if(op==2)
        {
            del(x);
        }
        if(op==3)
        {
            cout<<query(x)<<endl;
        }
        cout<<"done"<<endl;
    }
    n=read(),m=read();
    for(int i=1;i<=n;i++)
    {
        a[i]=read();
        c.push_back(a[i]);
    }
    for(int i=1;i<=m;i++)
    {
        b[i]=read();
        c.push_back(b[i]);
    }
    sort(c.begin(),c.end());
    c.erase(unique(c.begin(),c.end()),c.end());
    for(int i=1;i<=n;i++)
    {
        a[i]=lower_bound(c.begin(),c.end(),a[i])-c.begin();
        sum[a[i]]+=c[a[i]];
    }
    int l=c.size();
    for(int i=0;i<l;i++)
        insert(sum[i]);
    for(int i=1;i<=m;i++)
    {
        b[i]=lower_bound(c.begin(),c.end(),b[i])-c.begin();
        split(rt,x,y,sum[b[i]]-1);
        split(y,y,z,sum[b[i]]);
        y=merge(ls(y),rs(y));
        split(z,z,zz,sum[b[i]]+c[b[i]]);
        sum[b[i]]+=c[b[i]];
        rt=merge(merge(merge(x,y),z),merge(newnode(sum[b[i]]),zz));
        // cout<<query(l-i)<<" ";
        write(query(l-i));
        putchar(' ');
        
    }

    return 0;
}