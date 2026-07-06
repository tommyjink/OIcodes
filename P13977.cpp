#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int a[N],n,len,id[N],L[N],R[N],tag[N],sum[N];
void build()
{
    for(int i=1;i<=n;i++)
    {
        id[i]=(i-1)*len+1;
        if(!L[id[i]])L[id[i]]=i;
        R[id[i]]=i;
        sum[id[i]]+=a[i];
    }
}
void add(int l,int r,int d)
{
    if(id[l]==id[r])
    {
        for(int i=l;i<=r;i++)a[i]+=d;
        return;
    }
    for(int i=id[l]+1;i<=id[r]-1;i++)
        sum[i]+=d*(R[id[i]]-L[id[i]]+1),tag[i]+=d;
    for(int i=l;i<=R[l];i++)a[i]+=d;
    for(int i=L[r];i<=r;i++)a[i]+=d;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;len=sqrt(n);
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int t=1;t<=n;t++)
    {
        int op,l,r,c;
        cin>>op>>l>>r>>c;

    }
    return 0;
}