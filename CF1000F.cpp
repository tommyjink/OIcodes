#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,a[N],q,id[N],cnt[N],ans[N],sum[N];
int len=2000;
struct node
{
    int qid,l,r;
}b[N];
inline bool cmp(const node &x,const node &y)
{
    if(id[x.l]==id[y.l])return id[x.l]&1?x.r<y.r:x.r>y.r;
    else return id[x.l]<id[y.l];
}
inline void add(int x)
{
    // cout<<"add:"<<x<<endl;
    cnt[x]++;
    if(cnt[x]==1)sum[id[x]]++;
    if(cnt[x]==2)sum[id[x]]--;
}
inline void del(int x)
{
    // cout<<"del:"<<x<<endl;
    cnt[x]--;
    if(cnt[x]==1)sum[id[x]]++;
    if(cnt[x]==0)sum[id[x]]--;
}
int query()
{
    for(int i=1;i<=id[n];i++)
    {
        if(!sum[i])continue;
        int l=(i-1)*len,r=l+len;
        for(int j=l;j<r;j++)
        {
            if(cnt[j]==1)return j;
        }
    }
    return 0;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=0;i<N;i++)
        id[i]=i/len+1;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    cin>>q;
    for(int i=1;i<=q;i++)
    {
        b[i].qid=i;
        cin>>b[i].l>>b[i].r;
    }
    sort(b+1,b+1+q,cmp);
    int l=1,r=0;
    for(int i=1;i<=q;i++)
    {
        while(l>b[i].l)add(a[--l]);
        while(l<b[i].l)del(a[l++]);
        while(r<b[i].r)add(a[++r]);
        while(r>b[i].r)del(a[r--]);
        ans[b[i].qid]=query();
    }
    for(int i=1;i<=q;i++)
        cout<<ans[i]<<endl;
    return 0;
}