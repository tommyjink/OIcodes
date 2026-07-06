#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=2e5+100;
int n,a[N],L[N],R[N];
pii b[N];
struct node
{
    int l,r,frt,bck,val;
}t[N*4];
void pushup(int k)
{
    t[k].val=t[k*2].val+t[k*2+1].val;
    t[k].frt=max({t[k*2].frt,t[k*2].val+t[k*2+1].frt,0ll});
    t[k].bck=max({t[k*2+1].bck,t[k*2+1].val+t[k*2].bck,0ll});
}
void build(int k,int l,int r)
{
    t[k].l=l,t[k].r=r;
    if(l==r)
    {
        t[k].val=t[k].frt=t[k].bck=1;
        return;
    }
    int mid=(l+r)>>1;
    build(k*2,l,mid);
    build(k*2+1,mid+1,r);
    pushup(k);
}
void modify(int k,int x,int d)
{
    if(t[k].l>x||t[k].r<x)return;
    if(t[k].l==t[k].r)
    {
        a[t[k].l]=d;
        t[k].val=d;
        t[k].frt=t[k].bck=max(d,0ll);
        return;
    }
    modify(k*2,x,d);
    modify(k*2+1,x,d);
    pushup(k);
}
pii query_frt(int k,int l,int r)
{
    if(t[k].r<l||t[k].l>r||l>r)return pii(0,0);
    if(l<=t[k].l&&t[k].r<=r)return pii(t[k].val,t[k].frt);
    pii x=query_frt(k*2,l,r),y=query_frt(k*2+1,l,r);
    return pii(x.first+y.first,max({0ll,x.first+y.second,x.second}));
}
pii query_bck(int k,int l,int r)
{
    if(t[k].r<l||t[k].l>r||l>r)return pii(0,0);
    if(l<=t[k].l&&t[k].r<=r)return pii(t[k].val,t[k].bck);
    pii x=query_bck(k*2,l,r),y=query_bck(k*2+1,l,r);
    return pii(x.first+y.first,max({0ll,y.first+x.second,y.second}));
}
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i],b[i]=pii(a[i],i);
    stack<int> st;
    for(int i=1;i<=n;i++)
    {
        while(!st.empty()&&a[i]<=a[st.top()])st.pop();
        if(st.empty())L[i]=1;
        else L[i]=st.top()+1;
        st.push(i);
    }
    while(!st.empty())st.pop();
    for(int i=n;i>=1;i--)
    {
        while(!st.empty()&&a[i]<=a[st.top()])st.pop();
        if(st.empty())R[i]=n;
        else R[i]=st.top()-1;
        st.push(i);
    }
    build(1,1,n);
    /* while(1)
    {
        for(int i=1;i<=n;i++)
                cout<<query_bck(1,i,i).first<<" ";
            cout<<endl;
        int op;
        cin>>op;
        if(op==1)
        {
            int x,y;
            cin>>x>>y;
            modify(1,x,y);
        }
        if(op==2)
        {
            int x,y;
            cin>>x>>y;
            cout<<query_bck(1,x,y).first<<" "<<query_bck(1,x,y).second<<endl;
        }
        if(op==3)
        {
            int x,y;
            cin>>x>>y;
            cout<<query_frt(1,x,y).first<<" "<<query_frt(1,x,y).second<<endl;
        }
            
    }*/
    sort(b+1,b+1+n);
    int x=0,ans=0;
    for(int i=1;i<=n;i++)
    {
        // int res=query_bck(1,L[b[i].second],b[i].second-1).second+a[b[i].second]+
        //       query_frt(1,b[i].second+1,R[b[i].second]).second;
        // cout<<b[x].first<<" "<<b[i].first<<" "<<res<<endl;
        while(query_bck(1,L[b[i].second],b[i].second-1).second+a[b[i].second]+
              query_frt(1,b[i].second+1,R[b[i].second]).second>=0)
        {
            ans=max(ans,b[x].first-b[i].first);
            // cout<<b[x].first<<" "<<b[i].first<<endl;
            // for(int i=1;i<=n;i++)
            //     cout<<query_bck(1,i,i).first<<" ";
            // cout<<endl;
            if(x==n)break;
            x++;
            if(b[x].first!=b[x-1].first)
            {
                modify(1,b[x-1].second,-1);
                for(int j=x-1;j>=2&&b[j].first==b[j-1].first;j--)
                {
                    modify(1,b[j-1].second,-1);
                }
            }
        }
    }
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}