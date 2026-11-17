#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=305,P=1e9+7;
int n,m,l[N],r[N],v[N],id[N];
int fl[N],fr[N],fac[N];
vector<int> b;
bool cmpl(int x,int y)
{
    return l[x]<l[y];
}
bool cmpr(int x,int y)
{
    return r[x]>r[y];
}
bool cmpv(int x,int y)
{
    return v[x]<v[y];
}
int get(int x)
{
    return lower_bound(b.begin(),b.end(),x)-b.begin()+1;
}
void solve()
{
    cin>>n>>m;
    b.clear();
    b.push_back(1);
    b.push_back(n);
    for(int i=1;i<=m;i++)
    {
        cin>>l[i]>>r[i]>>v[i],id[i]=i;
        b.push_back(l[i]);
        b.push_back(r[i]);
    }
    if(n==1)
    {
        sort(id+1,id+1+m,cmpv);
        int ans=0;
        for(int ii=1;ii<=m;ii++)
        {
            int i=id[ii];
            ans=(ans+fac[m-ii]*v[i]%P)%P;
        }
        cout<<ans<<endl;
        return;
    }
    sort(b.begin(),b.end());
    b.erase(unique(b.begin(),b.end()),b.end());
    n=get(n);
    for(int i=1;i<=m;i++)
        l[i]=get(l[i]),r[i]=get(r[i]);
    sort(id+1,id+1+m,cmpl);
    for(int i=0;i<=n;i++)
        fl[i]=0;
    fl[1]=1;
    for(int ii=1;ii<=m;ii++)
    {
        int i=id[ii];
        for(int j=r[i];j<=n;j++)
            fl[j]=fl[j]*2%P;
        for(int j=l[i];j<r[i];j++)
            fl[r[i]]=(fl[r[i]]+fl[j])%P;
    }
    sort(id+1,id+1+m,cmpr);
    for(int i=0;i<=n;i++)
        fr[i]=0;
    fr[n]=1;
    for(int ii=1;ii<=m;ii++)
    {
        int i=id[ii];
        for(int j=l[i];j>=1;j--)
            fr[j]=fr[j]*2%P;
        for(int j=r[i];j>l[i];j--)
            fr[l[i]]=(fr[l[i]]+fr[j])%P;
    }


    // for(int i=1;i<=n;i++)
    //     cout<<fl[i]<<" ";
    // cout<<endl;
    // for(int i=1;i<=n;i++)
    //     cout<<fr[i]<<" ";
    // cout<<endl;


    int ans=0;
    for(int i=1;i<=m;i++)
    {
        for(int x=l[i];x<=r[i];x++)
        {
            for(int y=x+1;y<=r[i];y++)
            {
                if(!fl[x]||!fr[y])continue;
                int cnt=0;
                for(int j=1;j<=m;j++)
                    if(l[j]<=x&&y<=r[j])
                        if(v[j]>v[i]||(v[i]==v[j]&&j>i))
                            cnt++;
                // cout<<"l,r:"<<l[i]<<"~"<<r[i]<<"  :"<<x<<","<<y<<":"<<fl[x]*fr[y]%P*v[i]%P*fac[cnt]<<endl;
                ans=(ans+fl[x]*fr[y]%P*v[i]%P*fac[cnt]%P)%P;
            }
        }
    }
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    fac[0]=1;
    for(int i=1;i<N;i++)
        fac[i]=fac[i-1]*2%P;
    int t;cin>>t;
    while(t--)solve();
    return 0;
}