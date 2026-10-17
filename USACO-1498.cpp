#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=1e6+10,P=1e9+7,INF=1e18;
int n,m,q,fac2[N];
int tot=0,x[N],siz[N],sum[N];
set<int> s;
void ins(int x)
{
    if(s.find(x)!=s.end())s.erase(x);
    else s.insert(x);
}
int qpow(int x,int y)
{
    int res=1;
    while(y)
    {
        if(y&1)res=res*x%P;
        y>>=1;
        x=x*x%P;
    }
    return res;
}
int cal(int l,int r)
{
    int ll=upper_bound(x+1,x+1+tot,l)-x-1;
    int rr=upper_bound(x+1,x+1+tot,r)-x-1;
    // cout<<ll<<","<<rr<<endl;
    if(ll==rr)
    {
        if(ll&1)return 0;
        return (qpow(2,r-l+1)-1+P)%P;
    }
    int lval=(ll&1)?0:(qpow(2,x[ll+1]-l)-1+P)%P;
    int rval=(rr&1)?0:(qpow(2,r-x[rr]+1)-1+P)%P;
    // cout<<lval<<"!"<<rval<<endl;
    if(ll+1<rr)
    {
        int mval=(sum[rr-1]-sum[ll]*qpow(2,x[rr]-x[ll+1])%P+P)%P;
        // cout<<sum[rr-1]<<","<<sum[ll]<<","<<mval<<"!!!"<<endl;
        return (rval+mval*qpow(2,r-x[rr]+1)%P+lval*qpow(2,r-x[ll+1]+1)%P)%P;
    }
    return (lval*qpow(2,r-x[ll+1]+1)%P+rval)%P;
}
int cnt(int l,int r)
{
    // cout<<l<<","<<r<<":"<<c[r]-c[l-1]<<endl;
    int ll=upper_bound(x+1,x+1+tot,l)-x-1;
    int rr=upper_bound(x+1,x+1+tot,r)-x-1;
    if(ll==rr)
    {
        if(ll&1)return 0;
        return r-l+1;
    }
    int lval=(ll&1)?0:x[ll+1]-l;
    int rval=(rr&1)?0:r-x[rr]+1;
    if(ll+1<rr)
    {
        int mval=siz[rr-1]-siz[ll];
        return lval+rval+mval;
    }
    return lval+rval;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    fac2[0]=1;
    for(int i=1;i<N;i++)
        fac2[i]=fac2[i-1]*2%P;
    cin>>n>>m>>q;
    for(int i=1;i<=m;i++)
    {
        int l,r;cin>>l>>r;
        ins(l),ins(r+1);
    }
    auto it=s.begin();
    x[++tot]=0;
    while(it!=s.end())x[++tot]=*it,it=next(it);
    x[++tot]=INF;
    // for(int i=1;i<=tot;i++)
    //     for(int j=x[i];j<min(50ll,x[i+1]);j++)cout<<((i&1)?0:1)<<" ";
    // cout<<endl;
    for(int i=1;i<tot;i++)
    {
        siz[i]=siz[i-1];
        sum[i]=sum[i-1]*qpow(2,x[i+1]-x[i])%P;
        if(!(i&1))
        {
            siz[i]+=x[i+1]-x[i];
            sum[i]=(sum[i]+qpow(2,x[i+1]-x[i])-1+P)%P;
        }
    }
    // for(int i=1;i<=tot;i++)
    //     cout<<sum[i]<<" ";
    // cout<<endl;
    // while(1)
    // {
    //     int l,r;
    //     cin>>l>>r;
    //     cout<<cal(l,r)<<" "<<cnt(l,r)<<endl;
    // }


    // for(int i=1;i<=n;i++)a[i]^=a[i-1],b[i]=a[i]+b[i-1];
    // for(int i=1;i<=n;i++)c[i]=(c[i-1]*2+a[i])%P;

    // for(int i=1;i<=n;i++)cout<<a[i]<<" ";
    // cout<<endl;
    // while(1)
    // {
    //     int l,r;
    //     cin>>l>>r;
    //     cout<<cal(l,r)<<endl;
    // }
    while(q--)
    {
        int L,R,k;
        cin>>L>>R>>k;
        if(cnt(L,R)>=k){cout<<(qpow(2,k)-1+P)%P<<endl;continue;}
        int l=L,r=R+1;
        while(l<r)
        {
            // cout<<l<<","<<r<<endl;
            int mid=(l+r+1)>>1;
            if(cnt(L,mid-1)+R-mid+1>=k)l=mid;
            else r=mid-1;
        }
        // cout<<l<<"!"<<" ";
        // if(l>R)cout<<cal(L,R)<<"!"<<endl;
        cout<<((qpow(2,k)-qpow(2,R-l+1)+cal(l,R))%P+P)%P<<endl;
        // cout<<"!!!!"<<endl;
    }
    return 0;
}