#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=2e5+10,M=12000000,mod=998244353;
int c,n,a[N],lim,ans,s;
signed rt,tot;
signed ls[M],rs[M],sum[M],cnt[M],val[M],num[M],lv[M],rv[M];

bool isleaf(signed x)
{
    return x&&!ls[x]&&!rs[x];
}

signed newnode(int x,int y)
{
    if(!x||!y)return 0;
    signed p=++tot;
    ls[p]=rs[p]=0;
    val[p]=lv[p]=rv[p]=x;
    num[p]=y;
    sum[p]=x*y;
    cnt[p]=y%mod;
    return p;
}

signed merge(signed x,signed y);

signed make(signed x,signed y)
{
    if(!x)return y;
    if(!y)return x;
    signed p=++tot;
    ls[p]=x,rs[p]=y;
    val[p]=num[p]=0;
    sum[p]=sum[x]+sum[y];
    cnt[p]=(cnt[x]+cnt[y])%mod;
    lv[p]=lv[x],rv[p]=rv[y];
    return p;
}

signed cutl(signed x,signed &y)
{
    if(isleaf(x))
    {
        y=x;
        return 0;
    }
    signed t=cutl(ls[x],y);
    return merge(t,rs[x]);
}

signed cutr(signed x,signed &y)
{
    if(isleaf(x))
    {
        y=x;
        return 0;
    }
    signed t=cutr(rs[x],y);
    return merge(ls[x],t);
}

signed merge(signed x,signed y)
{
    if(!x)return y;
    if(!y)return x;
    if(rv[x]==lv[y])
    {
        signed a,b;
        x=cutr(x,a);
        y=cutl(y,b);
        signed z=newnode(rv[a],num[a]+num[b]);
        return merge(merge(x,z),y);
    }
    return make(x,y);
}

signed getpre(signed x,int k)
{
    if(!x||k<=0)return 0;
    if(sum[x]<=k)return x;
    if(isleaf(x))
    {
        signed res=0;
        int q=k/val[x],r=k%val[x];
        if(q)res=merge(res,newnode(val[x],q));
        if(r)res=merge(res,newnode(r,1));
        return res;
    }
    if(k<=sum[ls[x]])return getpre(ls[x],k);
    return merge(ls[x],getpre(rs[x],k-sum[ls[x]]));
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>c>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]>lim)lim=a[i];
    }
    for(int i=n;i>=1;i--)
    {
        signed p;
        if(a[i]>s)p=merge(rt,newnode(a[i]-s,1));
        else p=getpre(rt,a[i]);
        ans=(ans+cnt[p])%mod;
        s+=a[i];
        rt=merge(p,rt);
        if(sum[rt]>lim)rt=getpre(rt,lim);
    }
    cout<<(ans+1)%mod<<endl;
    return 0;
}
