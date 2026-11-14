#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define ls(x) t[x].l
#define rs(x) t[x].r
using namespace std;
const int N=1e6+10;
int n,m,a[N],b[N],tot;
int rt,x,y,z,sum[N];
vector<int> c;
struct node
{
    int l,r;
    int val,pri,siz,sum;
}t[N*2];
void pushup(int k)
{
    t[k].siz=t[ls(k)].siz+t[rs(k)].siz+1;
    t[k].sum=t[ls(k)].sum+t[rs(k)].sum+t[k].val;
}
int newnode(int val)
{
    t[++tot]=(node){0,0,val,rand()};
    return tot;
}
void split(int k,int &x,int &y,int val)
{
    if(!k){x=y=0;return;}
    if(t[k].val<=val)
    {
        x=k;
        split(y,rs(x),y,val);
        pushup(x);
    }
    else
    {
        y=k;
        split(y,x,ls(y),val);
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
void insert(int val)
{
    split(rt,x,y,val);
    rt=merge(x,merge(newnode(val),y));
}
void del(int val)
{
    split(rt,x,y,val-1);
    split(y,y,z,val);
    y=merge(ls(y),rs(y));
    rt=merge(merge(x,y),z);
}
int query(int siz)
{
    int k=rt,res=0;
    while(k)
    {
        int now=t[ls(k)].siz+1;
        if(now==siz)return res+t[ls(k)].sum+t[k].val;
        else if(now<siz)
        {
            res+=t[ls(k)].sum+t[k].val;
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
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    srand(time(0));
    while(1)
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
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        c.push_back(a[i]);
    }
    for(int i=1;i<=m;i++)
    {
        cin>>b[i];
        c.push_back(b[i]);
    }
    sort(c.begin(),c.end());
    c.erase(unique(c.begin(),c.end()),c.end());
    for(int i=1;i<=n;i++)
    {
        a[i]=lower_bound(c.begin(),c.end(),a[i])-c.begin();
        sum[a[i]]+=c[a[i]];
    }
    int ans=0;
    int l=c.size();
    for(int i=0;i<l;i++)
        insert(sum[i]),ans+=sum[i];
    for(int i=1;i<=m;i++)
    {
        b[i]=lower_bound(c.begin(),c.end(),b[i])-c.begin();
        del(sum[b[i]]);
        ans+=c[b[i]];
        sum[b[i]]+=c[b[i]];
        insert(sum[b[i]]);
        cout<<query(l-i)<<" ";
    }

    return 0;
}