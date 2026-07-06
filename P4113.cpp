#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=3e6+10;
int n,c,m,a[N],b[N],lst[N],t[N*2],ans[N];
struct node
{
    int l,r,num;
}q[N];
bool cmp(node x,node y)
{
    return x.r<y.r;
}
int lowbit(int x)
{
    return x&(-x);
}
void add(int x,int y)
{
    for(int i=x;i<=n;i+=lowbit(i))
        t[i]+=y;
}
int query(int x)
{
    int res=0;
    for(int i=x;i>0;i-=lowbit(i))
        res+=t[i];
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>c>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i],lst[i]=b[a[i]],b[a[i]]=i;
    for(int i=1;i<=m;i++)
        cin>>q[i].l>>q[i].r,q[i].num=i;
    sort(q+1,q+1+m,cmp);
    int p=0;
    for(int i=1;i<=m;i++)
    {
        while(p<q[i].r)
        {
            p++;
            if(lst[p])
                add(lst[p],1);
            if(lst[lst[p]])
                add(lst[lst[p]],-1);
        }
        ans[q[i].num]=query(q[i].r)-query(q[i].l-1);
    }
    for(int i=1;i<=m;i++)
        cout<<ans[i]<<endl;
    return 0;
}