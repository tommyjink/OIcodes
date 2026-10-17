#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
const int N=600;
int n,s[N],f[N],tag[N],B[N],lst[N];
pii b[N];
bool in(int x,int *tag)
{
    cout<<"in "<<x<<" ";
    for(int i=1;i<=n;i++)
        cout<<tag[i];
    cout<<endl;
    bool res;cin>>res;
    return res;
}
bool out(int x,int *tag)
{
    cout<<"out "<<x<<" ";
    for(int i=1;i<=n;i++)
        cout<<tag[i];
    cout<<endl;
    bool res;cin>>res;
    return res;
}
void CDQ(int l,int r)
{
    if(l==r)
    {
        if(s[l]==1)
        {
            int cnt=0;
            for(int i=1;i<l;i++)
                if(s[i]==0)b[++cnt]={f[i],i};
            if(cnt==0){return;}
            sort(b+1,b+cnt+1,greater<pii>());
            int L=1,R=cnt+1;
            while(L<R)
            {   
                int mid=(L+R)>>1;
                for(int i=1;i<=n;i++)tag[i]=0;
                for(int i=1;i<=mid;i++)tag[b[i].second]=1;
                if(in(l,tag))R=mid;
                else L=mid+1;
            }
            if(L==cnt+1)return;
            f[l]=b[L].first+1;
            lst[l]=b[L].second;
        }
        return;
    }
    int mid=(l+r)>>1;
    CDQ(l,mid);
    vector<pii> A;
    int cnt=0;
    for(int i=l;i<=mid;i++)
        if(s[i]==1)A.push_back({f[i],i});
    for(int i=mid+1;i<=r;i++)
        if(s[i]==0)B[++cnt]=i;
    sort(A.begin(),A.end(),greater<pii>());
    for(auto [dp,x]:A)
    {
        for(int i=1;i<=n;i++)tag[i]=0;
        for(int i=1;i<=cnt;i++)tag[B[i]]=1;
        while(cnt&&out(x,tag))
        {
            int L=1,R=cnt;
            while(L<R)
            {
                int mid=(L+R)>>1;
                for(int i=1;i<=n;i++)tag[i]=0;
                for(int i=L;i<=mid;i++)tag[B[i]]=1;
                if(out(x,tag))R=mid;
                else L=mid+1;
            }
            f[B[L]]=max(f[B[L]],f[x]+1);
            if(f[B[L]]==f[x]+1)lst[B[L]]=x;
            cnt--;
            for(int i=L;i<=cnt;i++)B[i]=B[i+1];
            for(int i=1;i<=n;i++)tag[i]=0;
            for(int i=1;i<=cnt;i++)tag[B[i]]=1;
        }   
    }
    CDQ(mid+1,r);
}
signed main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>s[i],f[i]=1;
    CDQ(1,n);
    int p=1;
    for(int i=1;i<=n;i++)
        if(f[i]>f[p])p=i;
    cout<<"! "<<f[p]<<" ";
    vector<int> ans;
    while(p)ans.push_back(p),p=lst[p];
    reverse(ans.begin(),ans.end());
    for(int i:ans)cout<<i<<" ";
    return 0;
}