#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
const int N=1e5+10;
int n,m,cnt[30];
string s;
struct node
{
    int l,r,val,lazy;
}t[30][N*4];
void pushup(node *t,int k)
{
    t[k].val=t[k*2].val+t[k*2+1].val;
}
void pushdown(node *t,int k)
{
    if(t[k].lazy==-1)return;
    t[k*2].lazy=t[k*2+1].lazy=t[k].lazy;
    t[k*2].val=(t[k*2].r-t[k*2].l+1)*t[k].lazy;
    t[k*2+1].val=(t[k*2+1].r-t[k*2+1].l+1)*t[k].lazy;
    t[k].lazy=-1;
}
void build(node *t,int k,int l,int r)
{
    t[k].l=l,t[k].r=r;
    t[k].val=0;
    t[k].lazy=-1;
    if(l==r)return;
    int mid=(l+r)>>1;
    build(t,k*2,l,mid);
    build(t,k*2+1,mid+1,r);
    pushup(t,k);
}
void modify(node *t,int k,int l,int r,int d)
{
    if(t[k].l>r||t[k].r<l)return ;
    if(l<=t[k].l&&t[k].r<=r)
    {
        t[k].lazy=d;
        t[k].val=(t[k].r-t[k].l+1)*d;
        return;
    }
    pushdown(t,k);
    modify(t,k*2,l,r,d);
    modify(t,k*2+1,l,r,d);
    pushup(t,k);
}
int query(node *t,int k,int l,int r)
{
    if(t[k].l>r||t[k].r<l)return 0;
    if(l<=t[k].l&&t[k].r<=r)return t[k].val;
    pushdown(t,k);
    return query(t,k*2,l,r)+query(t,k*2+1,l,r);
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    // int n=10;
    // build(t[0],1,1,n);
    // while(1)
    // {
    //     int op;
    //     cin>>op;
    //     if(op==1)
    //     {
    //         int x,y,z;
    //         cin>>x>>y>>z;
    //         modify(t[0],1,x,y,z);
    //     }
    //     else
    //     {
    //         int x,y;
    //         cin>>x>>y;
    //         cout<<query(t[0],1,x,y)<<endl;
    //     }
    //     for(int i=1;i<=n;i++)
    //         cout<<query(t[0],1,i,i)<<" ";
    //     cout<<endl;
    // }
    cin>>n>>m>>s;
    s=" "+s;
    for(int i=0;i<='z'-'a';i++)
        build(t[i],1,1,n);
    for(int i=1;i<=n;i++)
        modify(t[s[i]-'a'],1,i,i,1);
    while(m--)
    {
        int x,y,tmp=0,ii=0;
        cin>>x>>y;
        memset(cnt,0,sizeof(cnt));
        for(int i=0;i<='z'-'a';i++)
        {
            cnt[i]=query(t[i],1,x,y);
            if(cnt[i]&1)tmp++,ii=i;
        }
        if(tmp>1)continue;
        // cout<<"!"<<endl;
        for(int i=0;i<='z'-'a';i++)
            modify(t[i],1,x,y,0);
        if(tmp)modify(t[ii],1,(x+y)>>1,(x+y)>>1,1);
        int l=x,r=y;
        for(int i=0;i<='z'-'a';i++)
        {
            if(cnt[i]<=1)continue;
            modify(t[i],1,l,l+cnt[i]/2-1,1);
            modify(t[i],1,r-cnt[i]/2+1,r,1);
            l+=cnt[i]/2;
            r-=cnt[i]/2;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<='z'-'a';j++)
        {
            if(query(t[j],1,i,i))s[i]=j+'a';
        }
        cout<<s[i];
    }

    return 0;
}