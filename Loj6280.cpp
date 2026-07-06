#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6;
int n,a[N],id[N],sum[N],len,tag[N],st[N],ed[N];
void add(int l,int r,int d)
{
    if(id[l]==id[r])
    {
        for(int i=l;i<=r;i++)
            a[i]+=d,sum[id[i]]+=d;
        return;
    }
    for(int i=l;i<=ed[id[l]];i++)
        a[i]+=d,sum[id[i]]+=d;
    for(int i=st[id[r]];i<=r;i++)
        a[i]+=d,sum[id[i]]+=d;
    for(int i=id[l]+1;i<=id[r]-1;i++)
        tag[i]+=d,sum[i]+=d*(ed[i]-st[i]+1);
}
int query(int l,int r,int p)
{
    int res=0;
    if(id[l]==id[r])
    {
        for(int i=l;i<=r;i++)
            res=(res+a[i]+tag[id[i]])%p;
        return res;
    }
    for(int i=l;i<=ed[id[l]];i++)
        res=(res+a[i]+tag[id[i]])%p;
    for(int i=st[id[r]];i<=r;i++)
        res=(res+a[i]+tag[id[i]])%p;
    for(int i=id[l]+1;i<=id[r]-1;i++)
        res=(res+sum[i])%p;
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    len=sqrt(n);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        id[i]=(i-1)/len+1;
        sum[id[i]]+=a[i];
        if(!st[id[i]])
            st[id[i]]=i;
        ed[id[i]]=i;
    }
    for(int i=1;i<=n;i++)
    {
        // cout<<"??";
        int op;
        cin>>op;
        if(op==0)
        {
            int l,r,c;
            cin>>l>>r>>c;
            add(l,r,c);
        }
        else
        {
            int l,r,c;
            cin>>l>>r>>c;
            cout<<query(l,r,c+1)<<endl;
        }
    }
    return 0;
}
/*
4
1 2 2 3
0 1 3 1
1 1 4 4
0 1 2 2
1 1 2 4
*/