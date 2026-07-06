#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define endl "\n"
using namespace std;
const int N=1e6+10;
const int MAXA=1e6;
int n,q,A[200005],B[200005];
struct node
{
    int l,r,cnt,sum;
}t[N*4];
void pushup(int k)
{
    t[k].cnt=t[k*2].cnt+t[k*2+1].cnt;
    t[k].sum=t[k*2].sum+t[k*2+1].sum;
}
void build(int k,int l,int r)
{
    t[k].l=l,t[k].r=r;
    t[k].cnt=t[k].sum=0;
    if(l==r) return;
    int mid=(l+r)>>1;
    build(k*2,l,mid);
    build(k*2+1,mid+1,r);
}
void update(int k,int val,int d)
{
    if(t[k].l==t[k].r)
    {
        t[k].cnt+=d;
        t[k].sum+=val*d;
        return;
    }
    int mid=(t[k].l+t[k].r)>>1;
    if(val<=mid) update(k*2,val,d);
    else update(k*2+1,val,d);
    pushup(k);
}
int query_topk(int k,int num)
{
    if(num<=0) return 0;
    if(t[k].cnt<=num) return t[k].sum;
    if(t[k].l==t[k].r) return t[k].l*num;
    if(t[k*2+1].cnt>=num) return query_topk(k*2+1,num);
    else return t[k*2+1].sum+query_topk(k*2,num-t[k*2+1].cnt);
}
multiset<int> s1,s2;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if(!(cin>>n>>q)) return 0;
    build(1,1,MAXA);
    int totA=0;
    for(int i=1;i<=n;i++)
    {
        cin>>A[i]>>B[i];
        update(1,A[i],1);
        totA+=A[i];
        if(B[i]==1) s1.insert(A[i]);
        else s2.insert(A[i]);
    }
    while(q--)
    {
        int w,x,y;
        cin>>w>>x>>y;
        update(1,A[w],-1);
        totA-=A[w];
        if(B[w]==1) s1.erase(s1.find(A[w]));
        else s2.erase(s2.find(A[w]));
        A[w]=x; B[w]=y;
        update(1,A[w],1);
        totA+=A[w];
        if(B[w]==1) s1.insert(A[w]);
        else s2.insert(A[w]);
        int k=s2.size();
        if(k==0) cout<<totA<<endl;
        else if(k==n) cout<<totA+query_topk(1,n-1)<<endl;
        else
        {
            int extra=query_topk(1,k);
            int min_s2=*s2.begin();
            int max_s1=*s1.rbegin();
            if(min_s2>max_s1) extra=extra-min_s2+max_s1;
            cout<<totA+extra<<endl;
        }
    }
    return 0;
}