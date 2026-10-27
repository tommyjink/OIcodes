#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,k,t[N];
int cnt=0;
struct node
{
    int p,d;
}a[N*4];
bool cmp(node x,node y)
{
    return x.p<y.p;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>t[i];
    sort(t+1,t+1+n);
    for(int i=1;i<=n-1;i++)
    {
        if(t[i]+k<=t[i+1])continue;
        int l=t[i+1]-k+1,r=t[i];
        l=((l%k)+k)%k,r%=k;
        if(l<=r)a[++cnt]={l,1},a[++cnt]={r+1,-1};
        else a[++cnt]={l,1},a[++cnt]={0,1},a[++cnt]={r+1,-1};
    }
    sort(a+1,a+1+cnt,cmp);
    int p=-1,mx=0,now=0;
    for(int i=1;i<=cnt;i++)
    {
        int j=i;
        while(j<=cnt&&a[j].p==a[i].p)
        {
            now+=a[j].d;
            j++;
        }
        if(p==-1||now>=mx)mx=now,p=a[i].p;
        i=j-1;
    }
    cout<<n-mx<<endl;
    return 0;
}