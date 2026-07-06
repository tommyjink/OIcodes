#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
const int N=1e5+10,B=400;
int n,m,a[N],cnt[N],ans[N];
bitset<N+1> s1,s2;
struct node{int op,l,r,x,id;}q[N];
bool cmp(node x,node y)
{
    int xid=(x.l-1)/B,yid=(y.l-1)/B;
    if(xid!=yid)return xid<yid;
    else if(xid&1)return x.r<y.r;
    else return x.r>y.r;
}
void add(int x)
{
    s1[x]=s2[N-x]=true;
    cnt[x]++;
}
void del(int x)
{
    cnt[x]--;
    if(!cnt[x])s1[x]=s2[N-x]=false;
}
bool check1(int x)
{
    return (s1&(s1<<x)).any();
}
bool check2(int x)
{
    return (s1&(s2>>(N-x))).any();
}//a,N-x+a
bool check3(int x)
{
    if(x==0)return cnt[0];
    for(int i=1;i*i<=x;i++)
        if(x%i==0&&cnt[i]&&cnt[x/i])
            return true;
    return false;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=m;i++)cin>>q[i].op>>q[i].l>>q[i].r>>q[i].x,q[i].id=i;
    sort(q+1,q+1+m,cmp);
    int l=1,r=0;
    for(int i=1;i<=m;i++)
    {
        while(l>q[i].l)add(a[--l]);
        while(r<q[i].r)add(a[++r]);
        while(r>q[i].r)del(a[r--]);
        while(l<q[i].l)del(a[l++]);
        if(q[i].op==1)ans[q[i].id]=check1(q[i].x);
        if(q[i].op==2)ans[q[i].id]=check2(q[i].x);
        if(q[i].op==3)ans[q[i].id]=check3(q[i].x);
    }
    for(int i=1;i<=m;i++)cout<<(ans[i]?("hana"):("bi"))<<endl;
    return 0;
}