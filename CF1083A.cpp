#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=2e5+10;
const int INF=1e18;
int n,k,q;
int a[N][6];
struct tree
{
    int mx[32],mn[32];
}t[N*4];
void pushup(int p)
{
    for(int i=0;i<(1<<k);i++)
    {
        t[p].mx[i]=max(t[p*2].mx[i],t[p*2+1].mx[i]);
        t[p].mn[i]=min(t[p*2].mn[i],t[p*2+1].mn[i]);
    }
}
void build(int p,int l,int r)
{
    if(l==r)
    {
        for(int i=0;i<(1<<k);i++)
        {
            int val=0;
            for(int j=0;j<k;j++)
            {
                if((i>>j)&1) val+=a[l][j];
                else val-=a[l][j];
            }
            t[p].mx[i]=t[p].mn[i]=val;
        }
        return;
    }
    int mid=(l+r)>>1;
    build(p*2,l,mid);
    build(p*2+1,mid+1,r);
    pushup(p);
}
void update(int p,int l,int r,int x,int b[])
{
    if(l==r)
    {
        for(int i=0;i<(1<<k);i++)
        {
            int val=0;
            for(int j=0;j<k;j++)
            {
                if((i>>j)&1) val+=b[j];
                else val-=b[j];
            }
            t[p].mx[i]=t[p].mn[i]=val;
        }
        return;
    }
    int mid=(l+r)>>1;
    if(x<=mid) update(p*2,l,mid,x,b);
    else update(p*2+1,mid+1,r,x,b);
    pushup(p);
}
struct res
{
    int mx[32],mn[32];
};
res query(int p,int l,int r,int ql,int qr)
{
    if(ql<=l&&r<=qr)
    {
        res tmp;
        for(int i=0;i<(1<<k);i++)
        {
            tmp.mx[i]=t[p].mx[i];
            tmp.mn[i]=t[p].mn[i];
        }
        return tmp;
    }
    int mid=(l+r)>>1;
    if(qr<=mid) return query(p*2,l,mid,ql,qr);
    if(ql>mid) return query(p*2+1,mid+1,r,ql,qr);
    res L=query(p*2,l,mid,ql,qr);
    res R=query(p*2+1,mid+1,r,ql,qr);
    res ans_res;
    for(int i=0;i<(1<<k);i++)
    {
        ans_res.mx[i]=max(L.mx[i],R.mx[i]);
        ans_res.mn[i]=min(L.mn[i],R.mn[i]);
    }
    return ans_res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        for(int j=0;j<k;j++)
            cin>>a[i][j];
    build(1,1,n);
    cin>>q;
    while(q--)
    {
        int opt;
        cin>>opt;
        if(opt==1)
        {
            int i,b[6];
            cin>>i;
            for(int j=0;j<k;j++) cin>>b[j];
            update(1,1,n,i,b);
        }
        else
        {
            int l,r;
            cin>>l>>r;
            res final_res=query(1,1,n,l,r);
            int ans=0;
            for(int i=0;i<(1<<k);i++)
                ans=max(ans,final_res.mx[i]-final_res.mn[i]);
            cout<<ans<<endl;
        }
    }
    return 0;
}