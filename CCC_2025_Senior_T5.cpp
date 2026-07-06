#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+100,P=1e6+3;
int q,n,ans[N],tag[N*4],cnt[N];
vector<int> loc,cc;
struct node
{
    int l,r,maxval;
}t[N*4];
void pushdown(int k)
{
    t[k*2].maxval+=tag[k];
    t[k*2+1].maxval+=tag[k];
    tag[k*2]+=tag[k];
    tag[k*2+1]+=tag[k];
    tag[k]=0;
}
void pushup(int k)
{
    t[k].maxval=max(t[k*2].maxval,t[k*2+1].maxval);
}
void build(int k,int l,int r)
{
    t[k].l=l,t[k].r=r;
    if(l==r)return;
    int mid=(l+r)>>1;
    build(k*2,l,mid);
    build(k*2+1,mid+1,r);
    pushup(k);
}
void add(int k,int l,int r,int d)
{
    if(t[k].l>r||t[k].r<l)return;
    if(l<=t[k].l&&t[k].r<=r)
    {
        t[k].maxval+=d;
        tag[k]+=d;
        return;
    }
    pushdown(k);
    add(k*2,l,r,d);
    add(k*2+1,l,r,d);
    pushup(k);
}
int query(int k,int l,int r)
{
    if(t[k].l>r||t[k].r<l)return 0;
    if(l<=t[k].l&&t[k].r<=r)return t[k].maxval;
    pushdown(k);
    return max(query(k*2,l,r),query(k*2+1,l,r));
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>q;
    int tt=q;
    n=N-10;
    build(1,1,n);
    while(q--)
    {
        char ch;
        cin>>ch;
        if(ch=='A')
        {
            int x,y;
            cin>>x>>y;
            x=(x+ans[q+1])%P;
            y=(y+ans[q+1])%P;
            if(!cnt[x])
                add(1,x,x,x-1);
            cnt[x]++;
            loc.push_back(x);
            cc.push_back(y);
            add(1,1,x,y);
            ans[q]=query(1,1,n);
        }
        if(ch=='D')
        {
            int x;
            cin>>x;
            x=(x+ans[q+1])%P;
            int y=cc[x-1];
            x=loc[x-1];
            cnt[x]--;
            if(!cnt[x])
                add(1,x,x,1-x);
            add(1,1,x,-y);
            ans[q]=query(1,1,n);
        }
        // cout<<ans[q]<<endl;
    }
    for(int i=tt-1;i>=0;i--)
        cout<<ans[i]<<endl;
    return 0;
}