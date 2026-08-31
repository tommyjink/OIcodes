#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=5e5+10;
int n,a[N],b[N],c[N],d[N],cntb=0,tot=0,tag[N];
vector<int> v;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)cin>>b[i],cntb+=b[i];
    for(int i=1;i<=n;i++)cin>>c[i];
    for(int i=1;i<=n;i++)
    {
        if(!a[i])continue;
        a[i]+=c[i];c[i]=0;
        int tmp=min(a[i],b[i]);
        a[i]-=tmp;
        b[i]-=tmp;
        tot+=tmp;
    }
    for(int i=1;i<=n;i++)
    {
        if(!c[i]||!b[i])continue;
        if(!tot)continue;
        tot--;
        a[i]+=1+c[i];
        c[i]=0;
        int tmp=min(a[i],b[i]);
        a[i]-=tmp;
        b[i]-=tmp;
        tot+=tmp;
    }
    for(int i=1;i<=n;i++)
        if(c[i])v.push_back(c[i]);
    for(int i=1;i<=n;i++)
    {
        int res=a[i]+tot;
        if(res)res+=c[i];
        cout<<res<<" ";
    }
    cout<<endl;
    sort(v.begin(),v.end(),greater<int>());
    int ans=0;
    for(int i:v)
    {
        if(!i||!tot)break;
        tot--;
        ans+=1+i;
    }
    for(int i=1;i<=n;i++)
        ans+=a[i];
    cout<<ans+tot<<endl;
    return 0;
}